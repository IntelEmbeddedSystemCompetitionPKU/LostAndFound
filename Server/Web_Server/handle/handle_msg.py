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
    # sql='insert into Messages(username, targetname, message,time, objuuid) values("'+username+'", "'+targetname+'", "'+message+'", "'+str(time)+'", "'+objuuid+'");'
    sql='insert into Messages(username, targetname, message,time, objuuid) values(%s,%s,%s,%s,%s);'
    c.execute(sql, (username,targetname,message,str(time),objuuid))
    db.close()
    return 'True'


@app.route('/query/messages', methods=['POST'])
def handle_query_msg():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, objuuid, time = jdata['username'], jdata['targetuuid'], jdata['time']
    print(username+' get message after '+str(time))
    r=mc.query_sql('select message, time from Messages where objuuid=%s and targetname=%s and time>%s',(objuuid,username,str(time)))
    print(r)
    data='{"message_num":'+str(len(r))
    for i, u in enumerate(r):
        message, time = u[0], u[1]
        data+=',"message'+str(i)+'":"'+message+'",'+'"time'+str(i)+'":'+str(time)
    data+='}'
    print(data)
    return data

@app.route('/query/noreplylist', methods=['POST'])
def handle_query_noreplylist():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username = jdata['username']
    print(username+' get noreplylist ')
    # db,c=mc.cnnct()
    # subqery=' (select objuuid from Messages where username="'+username+'")'
    # sql='select distinct objuuid from Messages where targetname="'+username+'" and objuuid not in' +subqery
    # print(sql)
    # c.execute(sql)
    # r = c.fetchall()
    r=mc.query_sql('select distinct objuuid from Messages where targetname=%s and objuuid not in (select objuuid from Messages where username=%s)',(username,username))
    data='{"user_num":'+str(len(r))
    for i, u in enumerate(r):
        uuid=u[0]
        data+=',"user'+str(i)+'":"'+uuid+'"'
    data+='}'
    print(r)
    print(data)
    # db.close()
    return data

@app.route('/upload/pass', methods=['POST'])
def handle_upload_pass():
    jdata = json.loads(request.get_data().decode('utf-8'))
    username, objuuid = jdata['username'], jdata['targetuuid']
    print(username+' thinks '+objuuid+' is right!')
    # db,c=mc.cnnct()
    # sql='select distinct username, targetname from Messages where objuuid="'+objuuid+'";'
    r=mc.query_sql('select distinct username, targetname from Messages where objuuid=%s',(objuuid))
    # r=c.fetchall()
    if username==r[0][0]:
        targetname=r[0][1]
    else:
        targetname=r[0][0]
    mc.nofetchall_sql('update Lost set ownername=%s where objuuid=%s',(targetname,objuuid))
    # c.execute(sql)
    # db.close()
    return 'True'