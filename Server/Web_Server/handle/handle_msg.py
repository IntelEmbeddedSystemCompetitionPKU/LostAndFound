from Web_Server import app
from flask import request, send_file, send_from_directory
import crypt
#from Crypto.L
import uuid
import qrcode
import json
import Web_Server.db_op.mysql_connect as mc

@app.route('/upload/message', methods=['POST'])
def handle_upload_msg():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, objuuid, message, time = jdata['username'], jdata['targetuuid'], jdata['message'], jdata['time']
    db,c=mc.cnnct()
    sql='select distinct username, targetname from Messages where objuuid="'+objuuid+'";'
    print(sql)
    c.execute(sql)
    r=c.fetchall()
    if username==r[0][0]:
        targetname=r[0][1]
    else:
        targetname=r[0][0]
    print(username+' sent '+message+' to '+targetname+' about '+objuuid+'at time:',time)
    sql='insert into Messages(username, targetname, message,time, objuuid) values("'+username+'", "'+targetname+'", "'+message+'", "'+str(time)+'", "'+objuuid+'");'
    print(sql)
    c.execute(sql)
    db.close()
    return 'True'


@app.route('/query/messages', methods=['POST'])
def handle_query_msg():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, objuuid, time = jdata['username'], jdata['targetuuid'], jdata['time']
    print(username+' get message after '+str(time))
    db,c=mc.cnnct()
    # sql='select findername from Lost where objuuid="'+objuuid+'";'
    # print(sql)
    # c.execute(sql)
    # r=c.fetchall()
    # thename=r[0][0]
    sql='select message, time from Messages where objuuid="'+objuuid+'" and targetname="'+username+'" and time>"'+str(time)+'";'
    c.execute(sql)
    r = c.fetchall()
    print(r)
    data='{"message_num":'+str(len(r))
    for i, u in enumerate(r):
        message, time = u[0], u[1]
        data+=',"message'+str(i)+'":"'+message+'",'+'"time'+str(i)+'":'+str(time)
    data+='}'
    print(data)
    db.close()
    return data

@app.route('/query/noreplylist', methods=['POST'])
def handle_query_noreplylist():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username = jdata['username']
    print(username+' get noreplylist ')
    db,c=mc.cnnct()
    subqery=' (select objuuid from Messages where username="'+username+'")'
    sql='select distinct objuuid from Messages where targetname="'+username+'" and objuuid not in' +subqery
    print(sql)
    c.execute(sql)
    r = c.fetchall()
    data='{"user_num":'+str(len(r))
    for i, u in enumerate(r):
        uuid=u[0]
        data+=',"user'+str(i)+'":"'+uuid+'"'
    data+='}'
    print(r)
    print(data)
    db.close()
    return data

@app.route('/upload/pass', methods=['POST'])
def handle_upload_pass():
    print('handle_upload_pass')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, objuuid = jdata['username'], jdata['targetuuid']
    print(username+' thinks '+objuuid+' is right!')
    db,c=mc.cnnct()
    sql='select distinct username, targetname from Messages where objuuid="'+objuuid+'";'
    print(sql)
    c.execute(sql)
    r=c.fetchall()
    if username==r[0][0]:
        targetname=r[0][1]
    else:
        targetname=r[0][0]
    sql= 'update Lost set ownername="'+targetname+'" where objuuid="'+objuuid+'";'
    print(sql)
    c.execute(sql)
    db.close()
    return 'True'