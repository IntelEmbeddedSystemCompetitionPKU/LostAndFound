########################################################
# DESCRIPTION:
# handle functions about querying infomations
#
# AUTHOR: ykx
# TIME: 2018.06.21
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from Web_Server import app
from flask import request, send_file, send_from_directory
import json
import os
import pymysql
import base64
import qrcode
import Web_Server.db_op.mysql_connect as mc
basepath = '/home/ykx/Server_File/'

# order by similarity
def sort_lost(lostlist,keyword):
    words=keyword.split(' ')
    # keyword=keyword.replace(' ','')
    # chars=[c for c in keyword]
    # l=[[r,sum([1 for word in words if word in r[1]]), sum([1 for char in chars if char in r[1]]) ] for r in lostlist]
    l=[[r,sum([1 for word in words if word in r[1]]) ] for r in lostlist]
    l.sort(key=lambda x: -x[1])
    lostlist=[e[0] for e in l if e[1]>0]
    return lostlist


def lostlist2json(lostlist):
    data='{"uuid_num":'+str(len(lostlist))
    for i, r in enumerate(lostlist):
        data+=',num'+str(i)+':'+r[0]
    data+='}'
    print(data)
    return data

@app.route('/query/lostlist', methods=['POST'])
# description, date
def handle_query_lostlist():
    json_data = json.loads(request.get_data().decode('utf-8'))
    keyword, date = json_data['description'], json_data['date']
    print('query lost about '+keyword+' after '+date)
    #time_keywords_dict=time_keywords.split('_')
    lostlist = mc.query_mysql("objuuid,description", "Lost",'lostdate>='+date)
    lostlist=sort_lost(lostlist,keyword)
    print(lostlist)
    return lostlist2json(lostlist)

@app.route('/query/lostlist/available/<useruuid>', methods=['GET'])
def handle_query_available(useruuid):
    lostlist=mc.query_mysql("objuuid", "Lost",'owneruuid="'+useruuid+'"')
    return lostlist2json(lostlist)

@app.route('/query/lostlist/notapplied/<useruuid>', methods=['GET'])
def handle_query_applied(useruuid):
    lostlist=mc.query_mysql("objuuid", "Lost",'owneruuid="'+useruuid+'" and apply="0"')
    return lostlist2json(lostlist)

@app.route('/query/getinfo/<uuid>', methods=['GET'])
def handle_query_getinfo(uuid):
    lostlist=mc.query_mysql("description,lostdate", "Lost",'objuuid="'+uuid+'"')
    if len(lostlist)==0:
        return 'There is no such thing!'
    r=lostlist[0]
    ldpath = basepath + uuid + '/LD'
    data = '{"description": "' + r[0] + '", "time": "' + r[1] + '", "LD_num": "' + str(os.listdir(ldpath)) + '"}'
    print(data)
    return data


@app.route('/query/<uuid>/<picture_type>/<order>')
# uuid: uuid of object
# picture_type: LD, HD, mask
# order: 0, 1, 2, ...
def handle_query_LD(uuid, picture_type, order):
    path = basepath + uuid + '/' + picture_type + '/' + order + '.jpg'
    print(path)
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    return send_file(path,as_attachment=True)


@app.route('/query/maskinfo/<uuid>')
def handle_query_maskinfo(uuid):
    path = basepath + uuid
    print(path)
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    #picture = path + '/' + picture_type + '/' + picture_type + order + '.jpg'
    fr = open(path + '/data.txt', 'rb')
    jdata = json.loads(fr.read().decode('utf-8'))
    mask_num = jdata['mask_num']
    data = '{' + '"mask_num": "' + mask_num + '"'
    for k in range(0, int(mask_num)):
        data = data + ', "block' + str(k) + '_num": "' + json.dumps(jdata['mask']['mask' + str(k)]['block_num']) + '"'
    data = data + '}'
    return data


@app.route('/query/maskcheck/<uuid>')
def handle_query_maskcheck(uuid):
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))

    path = basepath + uuid
    print(path)
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    fr = open(path + '/data.txt', 'rb')
    answer = fr.read()
    answer = json.loads(answer)

    if answer['mask'] == json_data['mask']:
        db,c = mc.cnnct()
        c.execute("UPDATE Lost SET owneruuid=" + json_data['useruuid'] + " WHERE objuuid=" + uuid + ";")
        c.execute("UPDATE Lost SET apply='1' WHERE objuuid=" + uuid + ";")
        c.close()
        db.close()
        return 'True'
    else:
        return 'False'
    #mask_num = int(answer['mask_num'])
    #for k in range(0, mask_num):
    #    if (json_data['mask'] != answer['mask']):
    #        return 'False'
    #    else:
    #        return 'True'
