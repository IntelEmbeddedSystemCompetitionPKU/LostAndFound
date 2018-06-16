########################################################
# DESCRIPTION:
# handle functions about uploading files
#
# AUTHOR: ykx
# TIME: 2018.06.04
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from Web_Server import app
from flask import request
import json
import os
import pymysql

basepath = '/home/ykx/Server_File/'

##################
## Insert MySQL ##
##################

def insert_mysql(uuid, path):
    fr = open(path + '/data.txt', 'r')
    item_info = fr.read()
    item_info = json.loads(item_info)

    # connect to mysql
    conn = pymysql.connect("localhost", user='root', passwd='ykx970910', db='LostFound', charset='utf8')
    cursor = conn.cursor()
    # !!! need to modify !!!
    cursor.execute("INSERT INTO Lost(objuuid, lostdate, description) VALUES(" 
            #+ item_info['uuid'] + "," 
            + uuid + ","
            + item_info['time'] + ","
            + item_info['description']# + ","
            #+ item_info['mask_num'] + ","
            #+ item_info['usruuid']
            + ")")
    conn.commit()
    cursor.close()
    conn.close()

################
## APP client ##
################
@app.route('/upload/results', methods=['POST'])
def handle_upload_results():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))
    
    uuid = json_data['uuid']
    path = basepath + uuid
    
    fr = open(path + '/data.txt', 'r')
    info = fr.read()
    info = json.loads(info)
    fr.close()

    for k, v in json_data.items():
        if v != info[k]:
            return 0
    return 0
    #print(json_data['num_block'])
    #for _ in range(json_data['num_block']):
    #    print(json_data['block'+str(_+1)])
    
    #if (SQL_check_results(json_data) == 1):
    if (True): # FOR TEST
        return 1
    else:
        return 0


# json.loads(): transfer str to json
# json.dumps(): transfer json to str
# str has the function encode() and decode()
# decode('utf-8') transfer str to unicode
# encode('utf-8') transfer unicode to str

# write in json type, and its type is 'dict'

# <'dict'> --json.dumps()--> <'str'>

######################
## terminal mechine ##
######################

#uuid, description, time
@app.route('/upload/information', methods=['POST'])
def handle_upload_information():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))

    uuid = json_data['uuid']
    print(uuid)

    path = basepath + uuid
    if os.path.exists(path) == False:
        os.system('mkdir ' + path)
    fw = open(path + '/data.txt', 'a')
    for k, v in json_data.items():
        fw.write('"' + k + '": ' + '"' + v + '", ')
    fw.close()

    print(json_data['description'])
    #print(json_data['picture']) #??? what's this?
    print(json_data['time'])
    
    return 1 #FOR TEST

#uuid, mask_num, mask*, mask*.picture_num, mask*.picture*, mask*.block_num, mask*.block*
@app.route('/upload/mask', methods=['POST'])
def handle_upload_mask():
    uuid = json_data['uuid']
    path = basepath + uuid
    if os.path.exists(path) == False:
        return 0
    
    fw = open(path + '/data.txt', 'a')
    fw.write('"mask_num": ' + json_data['mask_num'] + ', ')
    for i in range(int(json_data['mask_num'])):
        fw.write('"mask' + str(i) + '": {')
        #fw.write('"picture_num": ' + json_data[['mask' + str(i)]['picture_num'] + ', ')
        #for j in range(int(json_data['mask' + str(i)]['picture_num'])):
        os.system('mkdir ' + path + '/mask' + str(i))

        # write mask*.jpg
        fp = open(path + '/mask' + '/picture' + str(i) + '.jpg', 'w')
        fp.write(json_data['mask' + str(i)]['picture'])
        fp.close()
            #fw.write('"picture' + str(j) + '": ' + json_data['mask' + str(i)]['picture' + str(j)] + ', ')
        
        # write mask*.block* information
        fw.write('"block_num": ' + json_data['mask' + str(i)]['block_num'] + ', ')
        for j in range(int(json_data['mask' + str(i)]['block_num'])):
            fw.write('"block' + str(j) + '": ' + json_data['block' + str(i)]['block' + str(j)] + ', ')
        fw.write('}, ')
    fw.close()

    
    return 1 # FOR TEST

#uuid, LD_num, LD*
@app.route('/upload/LD', methods=['POST'])
def handle_upload_LD():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))

    uuid = json_data['uuid']
    path = basepath + uuid
    if os.path.exists(path) == False:
        return 0
    fw = open(path + '/data.txt', 'a')
    fw.write('"LD_num": ' + json_data['LD_num'] + ', ')
    for _ in range(int(json_data['LD_num'])):
        #fw.write('"LD' + str(_) + '": ' + json_data['LD' + str(_)] + ', ')
        fp = open(path + '/LD' + '/picture' + str(_) + '.jpg', 'w')
        fp.write(json_data['LD' + str(_)])
        fp.close()
    fw.close()

    return 1 # FOR TEST

#uuid, HD_num, HD*
@app.route('/upload/HD', methods=['POST'])
def handle_upload_HD():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))

    uuid = json_data['uuid']
    path = basepath + uuid
    if os.path.exists(path) == False:
        return 0
    fw = open(path + '/data.txt', 'a')
    fw.write('"HD_num": ' + json_data['HD_num'] + ', ')
    for _ in range(int(json_data['HD_num'])):
        #fw.write('"HD' + str(_) + '": ' + json_data['HD' + str(_)] + ', ')
        fp = open(path + '/HD' + '/picture' + str(_) + '.jpg', 'w')
        fp.write(json_data['HD' + str(_)])
        fp.close()
    fw.close()

    return 1 # FOR TEST

#uuid, fetch_num, fetch*
@app.route('/upload/fetch', methods=['POST'])
def handle_upload_fetch():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))
    
    uuid = json_data['uuid']
    path = basepath + uuid
    if os.path.exists(path) == False:
        return 0
    fw = open(path + '/data.txt', 'a')
    fw.write('"fetch_num": ' + json_data['fetch_num'] + ', ')
    for _ in range(int(json_data['fetch_num'])):
        #fw.write('"fetch' + str(_) + '": ' + json_data['fetch' + str(_)] + ', ')
        fp = open(path + '/fetch' + '/picture' + str(_) + '.jpg', 'w')
        fp.write(json_data['fetch' + str(_)])
        fp.close()
    fw.close()

    return 1


#.tar.gz
@app.route('/upload/compress/<uuid>', methods=['POST'])
def handle_upload_compress(uuid):
    #data = request.get_data()
    files = request.files['file']
    #json_data = json.loads(data.decode('utf-8'))
    print(files)
    #print(json_data)
    #uuid = json_data['uuid']
    #uuid = data['uuid']
    path = basepath + uuid
    if os.path.exists(basepath + 'compress') == False:
        os.system('mkdir ' + basepath + 'compress')
    if os.path.exists(path) == False:
    #    return "False"
        os.system('mkdir ' + path)
    print ('mkdir')
    #files.save(basepath + 'compress/' + uuid + '.tar.gz')
    #fw = open(basepath + 'compress/' + uuid + '.tar.gz', 'w')
    #print ('fwrite')
    #fw.write(files)
    #fw.close()
    print(uuid)
    files.save(os.path.join(basepath, 'compress/' + uuid + '.tar.gz'))
    os.system('tar -xvf ' + basepath + 'compress/' + uuid + '.tar.gz -C ' + path)
    insert_mysql(uuid, path)
    #os.system('tree ' + basepath)
    #os.system('tar -xvf ' + basepath + 'compress/' + uuid + '.tar.gz')

    return 'True'

