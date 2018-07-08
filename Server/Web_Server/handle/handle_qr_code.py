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
from flask import request, send_file, send_from_directory
import crypt
#from Crypto.L
import uuid
import qrcode
import json
import Web_Server.db_op.mysql_connect as mc

qrimg_path='/home/lily/testqrcode.png'
# qrimg_path='/home/ykx/testqrcode.png'

@app.route('/query/qrcode_user', methods=['POST'])
def handle_query_qrcode_user():
    print('handle_query_qrcode_user')
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, passwd = jdata['username'], jdata['password']
    if not mc.is_password_right(username,passwd):
        return None
    print(username+' query his qrcode')
    info = username+passwd
    img = qrcode.make(info)
    img.save(qrimg_path)
    return send_file(qrimg_path,as_attachment=True)


@app.route('/query/qrcode_lost', methods=['POST'])
#私钥加密，板子上的公钥解密？
def handle_query_qrcode_lost():
    jdata = json.loads(request.get_data().decode('utf-8'))
    useruuid, itemuuid = jdata['useruuid'], jdata['itemuuid']
    sql_select='select * from Lost where objuuid="'+itemuuid+'" and owneruuid="'+useruuid+'";'
    sql_update='update Lost set apply="1"'+' where objuuid="'+itemuuid+'" and owneruuid="'+useruuid+'";'
    db,c = mc.cnnct()
    r=c.execute(sql_select)
    print(r)
    if r==0:
        return ''
    c.execute(sql_update)
    db.close()
    info = useruuid+'_'+itemuuid
    img = qrcode.make(info)
    img.save(qrimg_path)
    return send_file(qrimg_path,as_attachment=True)


@app.route('/query/qrcode_anti', methods=['POST'])
def handle_query_qrcode_anti():
    print('handle_query_qrcode_user')
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, passwd, dscpt = jdata['username'], jdata['password'], jdata['description']
    if not mc.is_password_right(username,passwd):
        return None
    print(username+'gets a qrcode with description: '+dscpt)
    try:
        code = username+dscpt+(uuid.uuid1().__str__().replace('-',''))
        db,c=mc.cnnct()
        sql='insert into Anti_qrcode values("'+username+'", "'+code+'");'
        c.execute(sql)
        img = qrcode.make(code)
        img.save(qrimg_path)
        db.close()
        return send_file(qrimg_path,as_attachment=True)
    except:
        return None