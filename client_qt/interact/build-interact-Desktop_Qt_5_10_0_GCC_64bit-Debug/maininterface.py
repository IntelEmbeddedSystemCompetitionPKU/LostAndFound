
# coding: utf-8

# In[ ]:


import json
import os
import storagemanager
#import gpio
#import upload
import time
import shutil
croot = '/home/richsoap/workspace/data/' 

def isexist(uuid):
    if storagemanager.is_exist(uuid):
        return tuple([0]) # 0 = true
    else:
        return tuple([1])

def isface(uuid):
    return tuple([0]) # 0 = true

def classify(uuid, number):
    for root, dirs, filename in os.walk(croot + uuid + '/OCR/'):
        for files in filename:
            print(root+files)
            if not files.find(str(number)) == -1:
                os.rename(root + files, root + str(number) + '.jpg')
                shutil.copyfile(root + str(number) + '.jpg', croot + uuid + '/mask/' + str(number) + '.jpg')
                break
    time.sleep(2)
    return

def loadresult(uuid, number):
    return tuple(["testing"])

def save(uuid):
    location = storagemanager.save_item(uuid)
    gpio.opendoor(location)
    #upload_tar(uuid)

def load(uuid):
    location = storagemanager.remove_item(uuid)
    gpio.opendoor(location)
    #upload_fecth(uuid)

def refresh(uuid, number, desc):

    return

def uploadMark(uuid, desc):
    return

def uploadPicker(uuid, desc):
    return 

