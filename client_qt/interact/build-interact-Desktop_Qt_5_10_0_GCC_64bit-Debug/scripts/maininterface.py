
# coding: utf-8

# In[ ]:


import json
import os
import storagemanager
#import gpio
import upload
import time
import shutil
import sys
import requests
from ocr_class import ocr_class
from face_detect import face_detecting
croot = '/home/upsquared/workspace/data/' 

def isexist(uuid):
    if storagemanager.is_exist(uuid):
        return tuple([0]) # 0 = true
    else:
        return tuple([1])

def isface(uuid):
    for root, dirs, filenames in os.walk(croot + uuid +'/fetch/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                os.rename(root + filename, root + 'face.jpg')
    result = face_deceting(croot + uuid + '/fetch/face.jpg')
    if True == result:
        return tuple([0])
    else:
        os.remove(croot + uuid + '/fetch/face.jpg')
        return tuple([1]) # 0 = true

def classify_img(uuid, number):
    for root, dirs, filename in os.walk(croot + uuid + '/OCR/'):
        for files in filename:
            print(root+files)
            if not files.find(str(number)) == -1:
                os.rename(root + files, root + str(number) + '.jpg')
                #shutil.copyfile(root + str(number) + '.jpg', croot + uuid + '/mask/' + str(number) + '.jpg')
                ocr_class.ocr_class(root + str(number) + '.jpg', croot + uuid + '/mask/')
                break
    return

def loadresult(uuid, number):
    result = "Something wrong"
    with open(croot + uuid + '/mask/' + str(number) + '.txt','r') as f:
        result = f.read()
    return tuple([result])

def save(uuid):
    location = storagemanager.save_item(uuid)
    #gpio.opendoor(location)
    upload.upload_path(croot + uuid + '/')

def load(uuid):
    location = storagemanager.remove_item(uuid)
    #gpio.opendoor(location)
    upload.upload_fecth(croot + uuid + '/')

def refresh(uuid, number, desc):
    with open(croot + uuid + '/mask/' + str(number) + '.txt','w') as f:
        f.write(desc)
    return

def uploadMark(uuid, desc):
    upload.upload_mark(uuid, desc)
    return

def uploadPicker(uuid, desc):
    upload.upload_picker(uuid, desc)
    return 

