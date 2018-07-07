
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

def upload_path(path):
    reshape_photos(path)
    generate_txt(path)
    targz_path(path)
    upload_targz(path)

def upload_fetch(base_url, imgdir):
    fetch_url = base_url + 'fetch'
    with open(imdir,'rb') as f:
        body = {'uuid':uuid,
               'fetch':f,
               #'time':time.asctime( time.localtime(time.time())
               }
        response = requests.post(ld_url, json=body)
        print(response.text)

def upload_mark(uuid, value):
    url = load_config('/etc/upload.json') + '/upload/labelinfo'
    body = {'uuid':uuid, 'value':value}
    res = requests.post(url, json=body)

def upload_picker(uuid, value):
    url = load_config('/etc/upload.json') + '/upload/finderinfo'
    body = {'uuid':uuid, 'username': value}
    res = resquests.post(url, json=body)

def load_config(config_dir, test=False):
    if(test == True):
        return 'http://httpbin.org/upload/'
    else:
        with open(config_dir, 'r') as f:
            data = json.load(f)
        return 'http://' + data['ip'] + ':' + data['port'] + '/upload/compress'

def upload_targz(rootdir):
    base_url = load_config('/etc/upload.json')
    generate_data(rootdir)
    targz_data(rootdir)
    with open(rootdir + 'upload.tar.gz','rb') as f:
        files = f.read()
        body = {
            'uuid':rootdir.split('/')[-2],
        }
        base_url = base_url + '/' + body['uuid']
        response = requests.post(base_url, json=body, files=f)

def generate_txt(rootdir):
    with open(rootdir + 'data.txt', 'w') as f:
        body = {}
        body['uuid'] = rootdir[-21:-1]
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
                            clip = lines.split
                            if len(clip) == 2:
                                if clip[0] == kind:
                                    totaldesc += clip[0]
                                    totaldesc += ';'
                                else:
                                    j += 1
                                    tempbody[clip[0]] = clip[1]
                            else:
                                totaldesc += clip[0]
                                totaldesc += ';'
                    tempbody['block_num'] = str(j)
                    body['mask' + str(i)] = tempbody
                    i += 1
            body['mask_num'] = str(i)
        body['fecth_num'] = str(0)
        body['desc'] = totaldesc
        json.dump(body, f)

def reshape_photos(path):
    count = 0
    for root, dirs, filenames in os.walk(path + 'mask/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                image = cv2.imread(root + filename)
                image = cv2.resize(image, (640,360))
                cv2.imwrite(path + 'LD/' + str(count) + '.jpg', image)
                count += 1
    for root, dirs, filenames in os.walk(path + 'HD/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                image = cv2.imread(root + filename)
                image = cv2.resize(image, (640,360))
                cv2.imwrite(path + 'LD/' + str(count) + '.jpg', image)
                count += 1

def targz_path(rootdir):
    os.system('tar -C' + rootdir +' -cvf ' + rootdir +'upload.tar.gz data.txt/ HD/ mask/ LD/')
    
        
