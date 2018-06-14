from Web_Server import app
from flask import request
import uuid
import sys
sys.path.append(r'/home/ykx/EmbeddedSystem/LostAndFound/Server/Web_Server/db_op')  
from sqlconnect import *

@app.route('/signup', methods=['POST'])
# 注册(用户名，密码(MD5，用公钥加密))(True,False)
def signup():
    jdata = json.loads(request.data)
    print(jdata['name']+' trys to sign up with password '+jdata['passwd'])
    #若不冲突且合法则存入数据库
    username=jdata['name']
    passwd=jdata['passwd']
    useruuid = uuid.uuid1().__str__().replace('_','')
    db,c = cnnct()
    try:
        c.execute('insert into User values('+username+','+passwd+','+useruuid+');')
    except:
        return 'False'
    return 'True'


@app.route('/signin', methods=['POST'])
# 登陆(用户名，密码(MD5，用公钥加密))(True,False)
def signin():
    print(jdata['name']+' trys to login with password '+jdata['passwd'])    
    jdata = json.loads(request.data)
    username=jdata['name']
    passwd=jdata['passwd']
    db,c = cnnct()
    try:
        r=c.execute('select * from User where username="'+username+'" and passwd="'+passwd+'";')
        if r==1:
            return 'True'
    except:
        return 'False'
    return 'True'
