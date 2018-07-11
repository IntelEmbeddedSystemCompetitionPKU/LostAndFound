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

# basepath = '/home/ykx/Server_File/'
basepath = '/home/lily/Server_File/'

##################
## Insert MySQL ##
##################

# used to insert information of lost property into database
def insert_mysql(uuid, path):
    fr = open(path + '/data.txt', 'r')
    item_info = json.loads(fr.read())
    print(item_info)
    # db, c = mc.cnnct()
    # sql = 'insert into Lost(objuuid, lostdate, description) VALUES("'
    # sql +=uuid + '","'
    # sql += item_info['time'] 
    # sql += '","'+ item_info['description']+ '");'
    mc.nofetchall_sql('insert into Lost(objuuid, lostdate, description) values(%s,%s,%s)',(uuid,item_info['time'],item_info['description']))
    #sql = 'insert into Lost(objuuid, lostdate, description) VALUES("'+ uuid + '","' + item_info['time'] + '","'+ item_info['description']+ '");'
    # print(sql)
    # c.execute(sql)
    # db.close()

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

# fetch
@app.route('/upload/fetch/<uuid>', methods=['POST'])
def handle_upload_fetch(uuid):
    files = request.files['file']
    path = basepath + uuid
    files.save(os.path.join(path, 'fetch.jpg'))
    return 'True'

@app.route('/upload/labelinfo', methods=['POST'])
def handle_upload_labelinfo():
    json_data = json.loads(request.get_data().decode('utf-8'))
    # get username and information of qrcode
    objuuid,anti_code = json_data['uuid'],json_data['value']
    db,c = mc.cnnct()
    l = anti_code.split('*')
    username=l[0]
    dscr=l[1]
    # sql = 'select useruuid from User where username="' + username + '";'
    # c.execute(sql)
    # print(sql)
    # results = c.fetchall()
    # owneruuid = results[0][0]
    # distribute owneruuid to lost property
    c.execute('update Lost set ownername=%s where objuuid=%s',(username,objuuid))
    # sql = 'UPDATE Lost SET description=concat("' + dscr + '" ,description) WHERE objuuid="' + objuuid + '";'
    c.execute('update Lost set description=concat(%s ,description) WHERE objuuid=%s',(dscr,objuuid))
    db.close()
    return 'True'

@app.route('/upload/finderinfo', methods=['POST'])
def handle_upload_finderinfo():
    json_data = json.loads(request.get_data().decode('utf-8'))
    username,objuuid = json_data['username'],json_data['uuid']
    # db,c = mc.cnnct()
    # c.execute('SELECT useruuid FROM User WHERE username="' + username + '";')
    # results = c.fetchall()
    # owneruuid = results[0][0]
    # distribute finderuuid to lost property
    # c.execute('UPDATE Lost SET findername="' + username + '" WHERE objuuid="' + objuuid + '";')
    mc.nofetchall_sql('update Lost set findername=%s where objuuid=%s',(username,objuuid))
    # db.close()
    return 'True'

