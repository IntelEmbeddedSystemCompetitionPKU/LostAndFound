
# coding: utf-8

# In[20]:

import json
import os
import time
import requests
import cv2
import gpio


def upload_path(path):
    reshape_photos(path)
    generate_txt(path)
    targz_path(path)
    upload_targz(path)

def upload_fetch(imgdir):
    fetch_url = base_url + 'fetch/' + imgdir.split('/')[-2]
    with open(imdir,'rb') as f:
        files = {'file':f}
        response = requests.post(fetch_url, files=files)

def upload_mark(uuid, value):
    url = load_config('/etc/upload.json') + 'labelinfo'
    body = {'uuid':uuid, 'value':value}
    res = requests.post(url, json=body)

def upload_picker(uuid, value):
    url = load_config('/etc/upload.json') + 'finderinfo'
    body = {'uuid':uuid, 'username': value}
    res = requests.post(url, json=body)

def load_config(config_dir, test=False):
    if(test == True):
        return 'http://httpbin.org/upload/'
    else:
        with open(config_dir, 'r') as f:
            data = json.load(f)
        return 'http://' + data['ip'] + ':' + data['port'] + '/upload/'

def upload_targz(rootdir):
    base_url = load_config('/etc/upload.json')  + 'compress/'
    with open(rootdir + 'upload.tar.gz','rb') as f:
        body = {
            'uuid':rootdir.split('/')[-2]
        }
        base_url = base_url + body['uuid']
        response = requests.post(base_url, files={'file':f})

def generate_txt(rootdir):
    with open(rootdir + 'data.txt', 'w') as fin:
        body = {}
        body['uuid'] = rootdir.split('/')[-2]
        totaldesc = ""
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
                if filename.endswith('.txt'):
                    tempbody = {}
                    j = 0
                    with open(root + filename,'r') as f:
                        for lines in f:
                            clips = lines.split(' ')
                            if len(clips) == 2:
                                if clips[0] == 'kind':
                                    totaldesc += clips[0]
                                    totaldesc += ';'
                                else:
                                    j += 1
                                    tempbody[clips[0]] = clips[1]
                            else:
                                totaldesc += clips[0]
                                totaldesc += ';'
                    tempbody['block_num'] = str(j)
                    body['mask' + str(i)] = tempbody
                    i += 1
            body['mask_num'] = str(i)
        body['fecth_num'] = str(0)
        body['description'] = totaldesc
        json.dump(body, fin)

def reshape_photos(path):
    if not os.path.exists(path + 'LD/'):
        os.mkdir(path + 'LD/')
    count = 0
    print('in mask')
    for root, dirs, filenames in os.walk(path + 'mask/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                image = cv2.imread(root + filename)
                image = cv2.resize(image, (640,480))
                cv2.imwrite(path + 'LD/' + str(count) + '.jpg', image)
                count += 1
    acount = 0
    print('in HD')
    for root, dirs, filenames in os.walk(path + 'HD/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                image = cv2.imread(root + filename)
                image = cv2.resize(image, (640,480))
                cv2.imwrite(path + 'LD/' + str(count) + '.jpg', image)
                count += 1
            os.rename(root + filename, root + str(acount) + '.jpg')

def targz_path(rootdir):
    os.system('tar -C' + rootdir +' -cvf ' + rootdir +'upload.tar.gz data.txt/ HD/ mask/ LD/')
    
        
