########################################################
# DESCRIPTION:
# handle functions about signup and signin
#
# AUTHOR: ykx
# TIME: 2018.06.21
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-
import sys
sys.path.append('.')
from Web_Server import app
# from handle_test_init import app
from flask import request
import json
import uuid
import os
import Web_Server.db_op.mysql_connect as mc

@app.route('/sign/signup', methods=['POST'])
# 注册(用户名，密码(MD5，用公钥加密))(True,False)
def handle_sign_signup():
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, passwd = jdata['username'], jdata['password']
    print(username+' trys to sign up with password '+passwd)
    #若不冲突且合法则存入数据库
    useruuid = uuid.uuid1().__str__().replace('-','')
    db,c=mc.cnnct()
    try:
        sql='insert into User values("'+username+'","'+passwd+'","'+useruuid+'");'
        r = c.execute(sql)
    except:
        db.close()
        return 'False'
    db.close()
    return 'True'


@app.route('/sign/signin', methods=['POST'])
# 登陆(用户名，密码(MD5，用公钥加密))(True,False)
# username, password
def handle_sign_signin():
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, passwd = jdata['username'], jdata['password']
    print(username+' trys to login with password '+passwd)
    return str(mc.is_password_right(username,passwd))
