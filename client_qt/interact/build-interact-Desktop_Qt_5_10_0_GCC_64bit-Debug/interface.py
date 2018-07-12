
# coding: utf-8

#import json
import time
import requests
import json
import os
import storagemanager
#import cv2
import gpio
import time
import shutil
import call_me
#import ocr_class
#from ./face_detect import face_detecting
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
    result = call_me.face_detecting(croot + uuid + '/fetch/face.jpg')
    if True == result:
        result = 'True'
    else:
        os.remove(croot + uuid + '/fetch/face.jpg')
        result = 'False' # 0 = true
    return tuple([result])


def classify_img(uuid, number):
    for root, dirs, filename in os.walk(croot + uuid + '/OCR/'):
        for files in filename:
            print('before class' + root+files)
            if str(number) in files:
                shutil.copyfile(root + files, croot + uuid + '/OCR/' + str(number-1) + '.jpg')
                shutil.copyfile(root + files, croot + uuid + '/mask/' + str(number-1) + '.jpg')
                with open(croot + uuid + '/mask/' + str(number - 1) + '.txt', 'w') as f:
                    f.write('kind card\n')
                    f.write('blank0 test')
                #call_me.ocr_class(root + str(number-1) + '.jpg', croot + uuid + '/mask/')
                return

def loadresult(uuid, number):
    result = "Something wrong"
    with open(croot + uuid + '/mask/' + str(number-1) + '.txt','r') as f:
        result = f.read()
    print(str(number - 1) + ' read ' + result)
    return tuple([result])


def save(uuid):
    location = storagemanager.save_item(uuid)
    print('after saving to storagemanager')
    print('save location ' + str(location))
    call_me.open_door(location)
    print('after opening door')
    upload_path(croot + uuid + '/')

def load(uuid):
    location = storagemanager.remove_item(uuid)
    print('load location ' + str(location))
    if not location == -1:
        call_me.open_door(location)
        upload_fecth(croot + uuid + '/')

def refresh(uuid, number, desc):
    with open(croot + uuid + '/mask/' + str(number-1) + '.txt','w') as f:
        f.write(desc)
    return
def uploadMark(uuid, desc):
    upload_mark(uuid, desc)
    return

def uploadPicker(uuid, desc):
    print('in upload Picker: ' + uuid + desc)
    upload_picker(uuid, desc)
    return 

#################################################################################################

def upload_path(path):
    reshape_photos(path)
    generate_txt(path)
    targz_path(path)
    upload_targz(path)

def upload_fetch(imgdir):
    base_url = load_config('/etc/upload.json')
    fetch_url = base_url + 'fetch/' + imgdir.split('/')[-2]
    with open(imdir,'rb') as f:
        response = requests.post(fetch_url, files={'file':f})

def upload_mark(uuid, value):
    url = load_config('/etc/upload.json') + 'labelinfo'
    body = {'uuid':uuid, 'value':value}
    res = requests.post(url, json=body)

def upload_picker(uuid, value):
    url = load_config('/etc/upload.json') + 'finderinfo'
    body = {'uuid':uuid, 'username': value}
    res = requests.post(url, json=body)
#########################################################
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
    print('in generate txt')
    with open(rootdir + 'data.txt', 'w') as fin:
        body = {}
        body['uuid'] = rootdir.split('/')[-2]
        totaldesc = ""
        body['time'] = time.strftime("%Y-%m-%d", time.localtime())
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
                            if 'blank' in clips[0]:
                                j += 1
                                if len(clips) == 1:
                                    tempbody[clips[0]] = ''
                                else:
                                    tempbody[clips[0]] = clips[1]
                            else:
                                totaldesc += lines
                                totaldesc += ';'
                    tempbody['block_num'] = str(j)
                    body['mask' + str(i)] = tempbody
                    i += 1
            body['mask_num'] = str(i)
        body['fecth_num'] = str(0)
        body['description'] = totaldesc
        json.dump(body, fin)
        print('out generate txt')


def reshape_photos(path):
    if not os.path.exists(path + 'LD/'):
        os.mkdir(path + 'LD/')
    count = 0
    uuid = path.split('/')[-2]
    print('in mask')
    for root, dirs, filenames in os.walk(path + 'mask/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                shutil.copyfile(root + filename, croot + uuid + '/LD/' + str(count) + '.jpg')
                count += 1
    acount = 0
    print('in HD')
    for root, dirs, filenames in os.walk(path + 'HD/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                shutil.copyfile(root + filename, croot + uuid + '/LD/' + str(count) + '.jpg')
                os.rename(root + filename, root + str(acount) + '.jpg')
                acount += 1

def targz_path(rootdir):
    os.system('tar -C' + rootdir +' -cvf ' + rootdir +'upload.tar.gz data.txt/ HD/ mask/ LD/')
    
