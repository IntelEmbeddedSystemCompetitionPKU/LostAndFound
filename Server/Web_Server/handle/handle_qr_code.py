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

@app.route('/usr_qr_code', methods=['POST'])
# 得到附有个人信息的二维码(用户名，密码(MD5，用公钥加密))(Image)
def get_usr_qr_code():
    jdata = json.loads(request.data)
    print(jdata['name']+'with password '+jdata['passwd']+' wants a qrcode'+jdata['description'])
    username=jdata['name']
    passwd=jdata['passwd']
    description=jdata['description']
    try:
        r=c.execute('select * from User where username="'+username+'" and passwd="'+passwd+'";')
        if r==0:
            return 'False'
        qrcode = username+'#'+description+'#'+uuid.uuid1().__str__().replace('_','')
        c.execute('insert into User_qrcode values('+username+','+qrcode+');')
        # img=qrcode.make(qrcode)
        # img.save("E:/Some.png")
        return qrcode
        # return json.dumps({})
    except:
        return 'False'


@app.route('/query/qrcode_user', methods=['POST'])
def handle_query_qrcode_user():
    print('handle_query_qrcode_user')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, passwd = jdata['username'], jdata['password']
    if not mc.is_password_right(username,passwd):
        return None
    print(username+' query his qrcode')
    info = username+passwd
    img = qrcode.make(info)
    img.save(qrimg_path)
    return send_file(qrimg_path,as_attachment=True)


@app.route('/query/qrcode_lost', methods=['POST'])
def handle_query_qrcode_lost():
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    if ('username' in jdata):
        info = jdata['useruuid'] + ' ' + jdata['password']
    elif ('useruuid' in jdata):
        info = jdata['useruuid'] + jdata['itemuuid']
    else:
        return 'Wrong query!'
    img = qrcode.make(info)
    img.get_image().show()
    print(img)
    img.save('/home/ykx/testqrcode.png')
    directory = '/home/ykx/'
    picture_dir = 'testqrcode.png'
    print(directory)
    return send_from_directory(directory, picture_dir, as_attachment=True)

@app.route('/query/qrcode_anti', methods=['POST'])
def handle_query_qrcode_anti():
    print('handle_query_qrcode_user')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
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