
# coding: utf-8

# In[20]:


import json
import os
import argparse
import time
import requests
import cv2

height = 200
width = 300

def start_process_new(rootdir):
    # step1 ocr images in './ocr', and save results to './mask'
    # step2 resize images in './HD' and './ocr', and save them to './LD'
    # step3 upload photos

    base_url = load_config('/etc/upload.json', test = True)
    os.mkdir(rootdir + '/mask/')
    os.mkdir(rootdir + '/LD/')
    print('start process')
    for root, dirs, files in os.walk(rootdir + 'ocr/'):
        for filename in files:
            process_image(os.path.join(root, filename), os.path.join(root, 'mask/'))
    # step 1 done
    
    for root, dirs, files in os.walk(rootdir + 'HD/'):
        for filename in files:
            resize_image(os.path.join(root, filename), os.path.join(root, 'LD/'))
    for root, dirs, files in os.walk(rootdir + 'ocr/'):
        for filename in files:
            resize_image(os.path.join(root, filename), os.path.join(root, 'LD/'))
    # step 2 done
    #upload_new(base_url, rootdir)
    upload_targz(base_url, rootdir)
    
def resize_image(srcdir, tardir):
    img = cv2.imread(srcdir)
    if img == None:
        return
    img = cv2.resize(img, (width, height))
    cv2.imwrite(tardir + srcdir.split('/')[-1],img)
    
def load_config(config_dir, test=False):
    if(test == True):
        return 'http://httpbin.org/upload/'
    else:
        with open(config_dir, 'r') as f:
            data = json.load(f)
    if(not data.has_key('ip')):
        data['ip'] = '10.127.171..75'
    if(not data.has_key('port')):
        data['port'] = '22'
    return 'http://' + data['ip'] + ':' + data['port'] + '/upload/'

def upload_targz(base_url, rootdir):
    generate_data(rootdir)
    targz_data(rootdir)
    with open(rootdir + 'upload.tar.gz','rb') as f:
        body = {
            'uuid':rootdir.split('/')[-1],
            'file':f
        }
        response = requests.post(base_url, json=body)

def generate_data(rootdir):
    
    
    
def targz_data(rootdir):
    os.system('tar cvf ' + rootdir + 'upload.tar ' + rootdir + 'data.txt ' + rootdir + 'HD ' + rootdir + 'mask LD')
    os.system('gzip ' + rootdir + 'upload.tar')
    

def upload_new(base_url, rootdir):
    uuid = rootdir.split('/')[-1]
    desc_url = base_url + 'description'
    body = {}
# step1 upload basic item information
    print('start upload basic information')
    with open(rootdir + 'description.txt', 'r') as f:
        desc = ''
        for lines in f:
            desc += lines
        body = {'uuid':uuid,
            'time':time.asctime( time.localtime(time.time())),
           'description':desc}

# step2 upload ld photos
    ld_url = base_url + 'LD'
    print('start upload LD images')
    for root, dirs, files in os.walk(rootdir + 'LD/'):
        i = 0
        for openfile in files:
            f = open(os.path.join(root, openfile),'rb')
            body['LD' + str(i)] = f
            i += 1
        body['LDnum'] = str(i)
                
# step3 upload hd photos
    hd_url = base_url + 'HD'
    print('start upload HD images')
    for root, dirs, files in os.walk(rootdir + 'HD/'):
        i = 0
        for openfile in files:
            f = open(os.path.join(root, openfile), 'rb')
            body['HD' + str()] = f
            i += 1
        body['HDnum'] = str(i)
            

# step4 upload mask photos
############################### 
#upload blanks at the same time?
###############################
    mask_url = base_url + 'mask'
    print('start upload mask images')
    for root, dirs, files in os.walk(rootdir + 'mask/'):
        i = 0
        for openfile in files:
            tempbody = {}
            if(openfile.endswith('jpg')):
                imgfile = open(os.path.join(root, openfile))
                blankfilename = openfile
                blankfilename[-4:] = '.txt'
                tempbody['image'] = f
                with open(os.path.join(root, blankfilename), 'r') as blankfile:
                    j = 0
                    for lines in blankfile:
                        tempbody['blank' + str(i)] = lines
                    tempbody['blanknum'] = str(i)
                

        
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


tarurl = load_config('./config.txt', test=True)
upload_new(tarurl, './testdata/')

