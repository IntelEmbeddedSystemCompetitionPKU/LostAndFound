from Web_Server import app
from flask import request
import json
import uuid
import sys
sys.path.append(r'/home/ykx/EmbeddedSystem/LostAndFound/Server/Web_Server/db_op')  
from sqlconnect import *

@app.route('/sign/signup', methods=['POST'])
# 注册(用户名，密码(MD5，用公钥加密))(True,False)
# username, password
def handle_sign_signup():
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    print(jdata['username']+' trys to sign up with password '+jdata['password'])
    #若不冲突且合法则存入数据库
    username=jdata['username']
    passwd=jdata['password']
    useruuid = uuid.uuid1().__str__().replace('_','')
    #db,c = cnnct()
    #try:
    #    c.execute('insert into User values('+username+','+passwd+','+useruuid+');')
    #except:
    #    return 'False'
    return 'True'


@app.route('/sign/signin', methods=['POST'])
# 登陆(用户名，密码(MD5，用公钥加密))(True,False)
# username, password
def handle_sign_signin():
    data = request.get_data()
    print(data)
    jdata = json.loads(data.decode('utf-8'))
    print(jdata)
    print(jdata['username']+' trys to login with password '+jdata['password'])    
    username=jdata['username']
    passwd=jdata['password']
    #db,c = cnnct()
    #try:
    #    r=c.execute('select * from User where username="'+username+'" and passwd="'+passwd+'";')
    #    if r==1:
    #        return 'True'
    #except:
    #    return 'False'
    return 'True'
