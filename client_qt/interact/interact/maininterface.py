
# coding: utf-8

# In[ ]:


import json
import os
import stroagemanager
import gpio
import upload
import time

def isexist(uuid):
    return tuple((0)) # 0 = true

def isface(uuid):
    return tuple((0)) # 0 = true

def classify(uuid, number):
    for root, dirs, filename in os.walk('~/workspace/data/' + uuid + '/'):
        for files in filename:
            if str(number) in files:
                os.rename(root + files, root + str(number) + '.jpg')
                break
    time.sleep(2)
    return

def loadresult(uuid, number):
    return str("testing")

def save(uuid):
    return

def load(uuid):
    return

def refresh(uuid, number):
    return

def uploadMark(uuid, desc):
    return

def uploadPicker(uuid, desc):
    return 

