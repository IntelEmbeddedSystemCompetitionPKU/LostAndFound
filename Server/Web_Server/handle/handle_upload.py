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
import Web_Server.db_op.mysql_connect as mc

basepath = '/home/ykx/Server_File/'

##################
## Insert MySQL ##
##################

# used to insert information of lost property into database
def insert_mysql(uuid, path):
    fr = open(path + '/data.txt', 'r')
    item_info = fr.read()
    item_info = json.loads(item_info)
    db, c = mc.cnnct()
    c.execute("INSERT INTO Lost(objuuid, lostdate, description) VALUES("
            + uuid + ","
            + item_info['time'] + ","
            + item_info['description']# + ","
            + ")")
    db.commit()
    c.close()
    db.close()

# json.loads(): transfer str to json
# json.dumps(): transfer json to str
# str has the function encode() and decode()
# decode('utf-8') transfer str to unicode
# encode('utf-8') transfer unicode to str

######################
## terminal mechine ##
######################

#.tar.gz
@app.route('/upload/compress/<uuid>', methods=['POST'])
def handle_upload_compress(uuid):
    # get the uploaded file
    files = request.files['file']
    # check if the same file exists
    path = basepath + uuid
    if os.path.exists(basepath + 'compress') == False:
        os.system('mkdir ' + basepath + 'compress')
    if os.path.exists(path) == False:
        os.system('mkdir ' + path)
    # save and decompress
    files.save(os.path.join(basepath, 'compress/' + uuid + '.tar.gz'))
    os.system('tar -xvf ' + basepath + 'compress/' + uuid + '.tar.gz -C ' + path)
    # insert information into database
    insert_mysql(uuid, path)
    return 'True'

@app.route('/upload/labelinfo', methods=['POST'])
def handle_upload_labelinfo():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))
    # get username and information of qrcode
    username = json_data['username']
    objuuid = json_data['value']
    db,c = mc.cnnct()
    c.execute("SELECT useruuid FROM User WHERE username=" + username + ";")
    results = c.fetchall()
    owneruuid = results[0][0]
    # distribute owneruuid to lost property
    c.execute("UPDATE Lost SET owneruuid=" + owneruuid + " WHERE objuuid=" + objuuid + ";")
    c.close()
    db.close()
    return 'True'

@app.route('/upload/finderinfo', methods=['POST'])
def handle_upload_finderinfo():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))
    # get username and objuuid
    username = json_data['username']
    objuuid = json_data['uuid']
    db,c = mc.cnnct()
    c.execute("SELECT useruuid FROM User WHERE username=" + username + ";")
    results = c.fetchall()
    owneruuid = results[0][0]
    # distribute finderuuid to lost property
    c.execute("UPDATE Lost SET finderuuid=" + owneruuid + " WHERE objuuid=" + objuuid + ";")
    c.close()
    db.close()
    return 'True'
