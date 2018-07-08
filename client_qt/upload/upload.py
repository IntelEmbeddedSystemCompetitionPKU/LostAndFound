
# coding: utf-8

# In[20]:

import numpy as np
import json
import os
import argparse
import time
import requests
import cv2
import gpio

height = 200
width = 300

def start_process_new(rootdir):
    # step1 ocr images in './ocr', and save results to './mask'
    # step2 resize images in './HD' and './ocr', and save them to './LD'
    # step3 upload photos

    base_url = load_config('/etc/upload.json', test = False)
    try: 
        os.mkdir(rootdir + 'mask/')
        os.mkdir(rootdir + 'LD/')
    except IOError:
        print('file exists')
    print('start process')
    count = 0
    for root, dirs, files in os.walk(rootdir + 'ocr/'):
        for filename in files:
            os.rename(os.path.join(root, filename), os.path.join(root, 'mask' + str(0) + '.jpg'))
            #ocr(os.path.join(root, filename), os.path.join(root, 'mask/'))
            #fakeocr(os.path.join(root, filename), os.path.join(root, 'mask/'))
    
    # step 1 done
    count = 0
    for root, dirs, files in os.walk(rootdir + 'HD/'):
        for filename in files:
            resize_image(os.path.join(root, filename), os.path.join(root, 'LD/'), count)
    for root, dirs, files in os.walk(rootdir + 'ocr/'):
        for filename in files:
            resize_image(os.path.join(root, filename), os.path.join(root, 'LD/'), count)
    # step 2 done
    #upload_new(base_url, rootdir)
    upload_targz(base_url, rootdir)
    
def resize_image(srcdir, tardir, count):
    img = cv2.imread(srcdir)
    print(srcdir)
    img = cv2.resize(img, (300, 200), interpolation=cv2.INTER_CUBIC)
    cv2.imwrite(tardir + 'LD' + str(count) + '.jpg',img)
    
def load_config(config_dir, test=False):
    if(test == True):
        return 'http://httpbin.org/upload/'
    else:
        with open(config_dir, 'r') as f:
            data = json.load(f)
        return 'http://' + data['ip'] + ':' + data['port'] + '/upload/compress'

def upload_targz(base_url, rootdir):
    generate_data(rootdir)
    targz_data(rootdir)
    with open(rootdir + 'upload.tar.gz','rb') as f:
        files = f.read()
        body = {
            'uuid':rootdir.split('/')[-2],
        }
        base_url = base_url + '/' + body['uuid']
        response = requests.post(base_url, json=body, files=f)

def generate_data(rootdir):
    with open(rootdir + 'data.txt', 'w') as f:
        body = {}
        body['uuid'] = rootdir[-21:-1]
        with open(rootdir + 'desc.txt','r') as des:
            body['description'] = des.read()
        body['time'] = time.asctime(time.localtime(time.time()))
        for root, dirs, files in os.walk(rootdir + 'HD/'):
            i = 0
            for filename in files:
                i += 1
            body['HD_num'] = str(i)
        for root, dirs, files in os.walk(rootdir + 'LD/'):
            i = 0
            for filename in files:
                i += 1
            body['LD_num'] = str(i)
        for root,dirs, files in os.walk(rootdir + 'mask/'):
            i = 0
            for filename in files:
                filename[-4:] = '.txt'
                tempbody = {}
                with open(filename, 'r') as f:
                    j = 0
                    for lines in f:
                        j += 1
                        tempbody['block' + str(j)] = lines
                i += 1
                tempbody['block_num'] = str(j)
                body['mask' + str(i)] = tempbody
            body['mask_num'] = str(i)
        body['fecth_num'] = str(0)
        json.dump(body, f)

                

    
    
def targz_data(rootdir):
    os.system('tar -C' + rootdir +' -cvf ' + rootdir +'upload.tar.gz data.txt/ HD/ mask/ LD/')
    
        
def upload_fetch(base_url, imgdir):
    fetch_url = base_url + 'fetch'
    with open(imdir,'rb') as f:
        body = {'uuid':uuid,
               'fetch':f,
               #'time':time.asctime( time.localtime(time.time())
               }
        response = requests.post(ld_url, json=body)
        print(response.text)


# In[19]:

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-srcdir',type=str)
    parser.add_argument('-mode',type=str)
    args = parser.parse_args()
    if(args.mode == 'new'):
        gpio.open_door(0)
        start_process_new(args.srcdir)
    elif(args.mode == 'old'):
        gpio.open_door(0)




