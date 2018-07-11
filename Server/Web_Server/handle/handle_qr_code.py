########################################################
# DESCRIPTION:
# handle functions about getting qrcode
#
# AUTHOR: ykx
# TIME: 2018.06.21
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from Web_Server import app
from flask import request, send_file#, send_from_directory
import crypt
#from Crypto.L
import uuid
import qrcode
import json
import Web_Server.db_op.mysql_connect as mc

basepath = '/home/lily/Server_File/'
qrimg_path='/home/lily/testqrcode.png'
blank_img = basepath+'default.png'
# qrimg_path='/home/ykx/testqrcode.png'

@app.route('/query/qrcode_user', methods=['POST'])
def handle_query_qrcode_user():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, passwd = jdata['username'], jdata['password']
    if not mc.is_password_right(username,passwd):
        return send_file(blank_img,as_attachment=True)
    print(username+' query his qrcode')
    code='user'+username#+passwd
    print(code)
    print('\n'*5)
    qrcode.make(code).save(qrimg_path)
    return send_file(qrimg_path,as_attachment=True)


@app.route('/query/qrcode_lost', methods=['POST'])
#私钥加密，板子上的公钥解密？
def handle_query_qrcode_lost():
    jdata = json.loads(request.get_data().decode('utf-8'))
    print(jdata)
    username, itemuuid = jdata['useruuid'], jdata['itemuuid']
    # sql_select='select * from Lost where objuuid="'+itemuuid+'" and ownername="'+username+'";'
    sql_select=('select * from Lost where objuuid=%s and ownername=%s',(itemuuid,username))
    # sql_update='update Lost set apply="1"'+' where objuuid="'+itemuuid+'" and ownername="'+username+'";'
    sql_update=('update Lost set apply="1" where objuuid=%s and ownername=%s',(itemuuid,username))
    # db,c = mc.cnnct()
    # r=c.execute(sql_select)
    r=mc.query_sql(*sql_select)
    if r==0:
        print('-'*6)
        print(sql_select)
        return send_file(blank_img,as_attachment=True)
    # r = c.execute(sql_update)
    r=mc.nofetchall_sql(*sql_update)
    if r==0:
        print('bad update')
    # db.close()
    code='fetc'+itemuuid
    qrcode.make(code).save(qrimg_path)
    return send_file(qrimg_path,as_attachment=True)
# fetc user mark

@app.route('/query/qrcode_anti', methods=['POST'])
def handle_query_qrcode_anti():
    jdata = json.loads(request.get_data().decode('utf-8'))
    print(jdata)
    username, passwd, dscpt = jdata['username'], jdata['password'], jdata['description']
    if not mc.is_password_right(username,passwd):
        return send_file(blank_img,as_attachment=True)
    print(username+'gets a qrcode with description: '+dscpt)
    code='mark'+username +'*'+ dscpt+'*'+(uuid.uuid1().__str__().replace('-',''))
    # db,c=mc.cnnct()
    # sql='insert into Anti_qrcode values("'+username+'", "'+code+'");'
    mc.nofetchall_sql('insert into Anti_qrcode(username,qrcode) values(%s,%s)',(username,code))
    # c.execute(sql)
    qrcode.make(code).save(qrimg_path)
    # db.close()
    return send_file(qrimg_path,as_attachment=True)
