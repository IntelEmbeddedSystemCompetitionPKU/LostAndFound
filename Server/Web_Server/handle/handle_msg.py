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
    username, targetname, message, time = jdata['username'], jdata['targetname'], jdata['message'], jdata['time']
    print(username+' sent '+message+' to '+targetname)
    db,c=mc.cnnct()
    sql='insert into Messages values("'+username+'", "'+targetname+'", "'+message+'", "'+time+'");'
    print(sql)
    c.execute(sql)
    db.close()
    return 'True'


@app.route('/query/messages', methods=['POST'])
def handle_query_msg():
    print('handle_query_msg')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username, targetname, time = jdata['username'], jdata['targetname'], jdata['time']
    print(username+' get message after '+str(time))
    db,c=mc.cnnct()
    sql='select * from Messages where username="'+username+'" and targetname="'+targetname+'" and time>"'+time+'";'
    c.execute(sql)
    r = c.fetchall()
    print(r)
    db.close()
    return 'True'

@app.route('/query/noreplaylist', methods=['POST'])
def handle_query_noreplylist():
    print('handle_query_noreplylist')
    data = request.get_data()
    jdata = json.loads(data.decode('utf-8'))
    username = jdata['username']
    print(username+' get noreplylist ')
    db,c=mc.cnnct()
    subqery=' (select targetname from Messages where username="'+username+'")'
    sql='select username from Messages where  targetname="'+username+'" and username not in' +subqery
    c.execute(sql)
    r = c.fetchall()
    print(r)
    db.close()
    return 'True'