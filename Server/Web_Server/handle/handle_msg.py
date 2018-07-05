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
    print('handle_upload_msg')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, targetuuid, message, time = jdata['username'], jdata['targetuuid'], jdata['message'], jdata['time']
    print(username+' sent '+message+' to '+targetuuid+'at time:',time)
    db,c=mc.cnnct()
    sql='select username from User where useruuid="'+targetuuid+'";'
    print(sql)
    c.execute(sql)
    r=c.fetchall()
    targetname=r[0][0]
    print('target name is',targetname)
    sql='insert into Messages values("'+username+'", "'+targetname+'", "'+message+'", "'+str(time)+'");'
    print(sql)
    c.execute(sql)
    db.close()
    return 'True'


@app.route('/query/messages', methods=['POST'])
def handle_query_msg():
    print('handle_query_msg')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, targetuuid, time = jdata['username'], jdata['targetuuid'], jdata['time']
    print(username+' get message after '+str(time))
    db,c=mc.cnnct()
    sql='select username from User where useruuid="'+targetuuid+'";'
    print(sql)
    c.execute(sql)
    r=c.fetchall()
    targetname=r[0][0]
    targetname, username = username, targetname
    print('target name is',targetname)
    sql='select message, time from Messages where username="'+username+'" and targetname="'+targetname+'" and time>"'+str(time)+'";'
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
    print('handle_query_noreplylist')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username = jdata['username']
    print(username+' get noreplylist ')
    db,c=mc.cnnct()
    subqery=' (select targetname from Messages where username="'+username+'")'
    sql='select distinct U.useruuid from Messages M, User U where  M.username=U.username and M.targetname="'+username+'" and M.username not in' +subqery
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