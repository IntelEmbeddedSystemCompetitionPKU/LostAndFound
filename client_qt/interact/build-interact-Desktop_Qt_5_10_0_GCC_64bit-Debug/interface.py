
# coding: utf-8

#import json
import time
import requests
import json
import os
import storagemanager
#import cv2
#import gpio
import time
import shutil
#from ocr_class import ocr_class
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
    result = face_deceting(croot + uuid + '/fetch/face.jpg')
    if True == result:
        return tuple([0])
    else:
        os.remove(croot + uuid + '/fetch/face.jpg')
        return tuple([1]) # 0 = true


def classify_img(uuid, number):
    number -= 1
    for root, dirs, filename in os.walk(croot + uuid + '/OCR/'):
        for files in filename:
            print(root+files)
            if not files.find(str(number)) == -1:
                os.rename(root + files, root + str(number) + '.jpg') 
                shutil.copyfile(root + str(number) + '.jpg', croot + uuid + '/mask/' + str(number) + '.jpg')
                with open(croot + uuid + '/mask/' + str(number) + '.txt', 'w') as f:
                    f.write('kind test')
                    f.write('\n')
                    f.write('blank0 testing')
                time.sleep(0.5)
                #ocr_class.ocr_class(root + str(number) + '.jpg', croot + uuid + '/mask/')
                
                break
    return

def loadresult(uuid, number):
    result = "Something wrong"
    with open(croot + uuid + '/mask/' + str(number) + '.txt','r') as f:
        result = f.read()
    return tuple([result])


def save(uuid):
    #location = storagemanager.save_item(uuid)
    #gpio.opendoor(location)
    upload_path(croot + uuid + '/')

def load(uuid):
    #location = storagemanager.remove_item(uuid)
    #gpio.opendoor(location)
    upload_fecth(croot + uuid + '/')

def refresh(uuid, number, desc):
    with open(croot + uuid + '/mask/' + str(number) + '.txt','w') as f:
        f.write(desc)
    return
def uploadMark(uuid, desc):
    upload_mark(uuid, desc)
    return

def uploadPicker(uuid, desc):
    upload_picker(uuid, desc)
    return 

#################################################################################################

def upload_path(path):
    #reshape_photos(path)
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
                            if clips[0].contains('blank'):
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


def reshape_photos(path):
    if not os.path.exists(path + 'LD/'):
        os.mkdir(path + 'LD/')
    count = 0
    print('in mask')
    for root, dirs, filenames in os.walk(path + 'mask/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                shutil.copyfile(root + str(number) + '.jpg', croot + uuid + '/LD/' + str(number) + '.jpg')
                #image = cv2.imread(root + filename)
                #image = cv2.resize(image, (640,480))
                #cv2.imwrite(path + 'LD/' + str(count) + '.jpg', image)
                count += 1
    acount = 0
    print('in HD')
    for root, dirs, filenames in os.walk(path + 'HD/'):
        for filename in filenames:
            if filename.endswith('.jpg'):
                shutil.copyfile(root + str(number) + '.jpg', croot + uuid + '/LD/' + str(number) + '.jpg')
                #image = cv2.imread(root + filename)
                #image = cv2.resize(image, (640,480))
                #cv2.imwrite(path + 'LD/' + str(count) + '.jpg', image)
                count += 1
                os.rename(root + filename, root + str(acount) + '.jpg')
                acount += 1

def targz_path(rootdir):
    os.system('tar -C' + rootdir +' -cvf ' + rootdir +'upload.tar.gz data.txt/ HD/ mask/ LD/')
    
