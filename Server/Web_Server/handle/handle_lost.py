########################################################
# DESCRIPTION:
# handle functions about querying infomations
#
# AUTHOR: fcg, ykx
# TIME: 2018.06.21
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from Web_Server import app
from flask import request, send_file#, send_from_directory
import json
import os
import pymysql
import base64
import qrcode
import Web_Server.db_op.mysql_connect as mc
from Levenshtein import distance as dist #字符串间的编辑距离

basepath = '/home/lily/Server_File/'
blank_img = basepath+'default.png'
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
    data='{"uuid_num":"'+str(len(lostlist))
    for i, r in enumerate(lostlist):
        data+='","uuid'+str(i)+'":"'+r[0]
    data+='"}'
    print(data)
    return data

@app.route('/query/lostlist', methods=['POST'])
# description, date
def handle_query_lostlist():
    json_data = json.loads(request.get_data().decode('utf-8'))
    keyword, date = json_data['description'], json_data['date']
    print('query lost about '+keyword+' after '+date)
    lostlist = mc.query_mysql('objuuid,description', 'Lost','lostdate>="'+date+'"')
    lostlist=sort_lost(lostlist,keyword)
    print(lostlist)
    return lostlist2json(lostlist)

@app.route('/query/lostlist/available/<username>', methods=['GET'])
def handle_query_available(username):
    lostlist=mc.query_mysql('objuuid', 'Lost','ownername="'+username+'"')
    return lostlist2json(lostlist)

@app.route('/query/lostlist/notapplied/<username>', methods=['GET'])
def handle_query_notapplied(username):
    lostlist=mc.query_mysql('objuuid', 'Lost','ownername="'+username+'" and apply="0"')
    return lostlist2json(lostlist)

@app.route('/query/getinfo/<uuid>', methods=['GET'])
def handle_query_getinfo(uuid):
    lostlist=mc.query_mysql('description,lostdate', 'Lost','objuuid="'+uuid+'"')
    if len(lostlist)==0:
        return 'There is no such thing!'
    r=lostlist[0]
    ldpath = basepath + uuid + '/LD'
    print(r)
    data = '{"description": "' + r[0] + '", "time": "' + r[1].isoformat()  + '", "LD_num": "' + str(len(os.listdir(ldpath))) + '"}'
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
        return send_file(blank_img,as_attachment=True)
    return send_file(path,as_attachment=True)


@app.route('/query/maskinfo/<uuid>', methods=['GET'])
def handle_query_maskinfo(uuid):
    path = basepath + uuid + '/data.txt'
    print(path)
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    fr = open(path, 'rb')
    jdata = json.loads(fr.read().decode('utf-8'))
    print(jdata)
    mask_num = jdata['mask_num']
    data = '{' + '"mask_num": "' + mask_num + '"'
    for k in range(0, int(mask_num)):
        data += ', "block' + str(k) + '_num":' + json.dumps(jdata['mask' + str(k)]['block_num'])
    data += '}'
    fr.close()
    return data


@app.route('/query/maskcheck/<username>/<objuuid>', methods=['POST'])
def handle_query_maskcheck(username,objuuid):
    json_data = json.loads(request.get_data().decode('utf-8'))
    path = basepath + objuuid
    # print(path)
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    # print(json_data)
    # return 'debug'
    fr = open(path + '/data.txt', 'rb')
    answer = fr.read()
    answer = json.loads(answer)
    # print(answer)
    cnt_right = 0
    cnt_all = 0
    len_sum = 0
    dis_sum = 0
    for item in json_data:
        itemjson = json.loads(json_data[item])
        for jtem in itemjson:
            cnt_all = cnt_all + 1
            print('compare real answer '+answer[item][jtem] + ' with user answer '+itemjson[jtem])
            len_sum+=len(answer[item][jtem])+len(itemjson[jtem])
            dis_sum+=dist(answer[item][jtem],itemjson[jtem])
            if answer[item][jtem] == itemjson[jtem]:
                cnt_right = cnt_right + 1
    # if dis_sum/len_sum<0.8:
    if cnt_right > cnt_all * 0.6:
        db,c = mc.cnnct()
        r=sql = 'UPDATE Lost SET ownername="' + username + '" WHERE objuuid="' + objuuid + '";'
        print(sql)
        if r==0:
            print('oops! no such obj')
        c.execute(sql)
        sql='UPDATE Lost SET apply="1" WHERE objuuid="' + objuuid + '";'
        print(sql)
        c.execute(sql)
        c.close()
        db.close()
        return 'True'
    else:
        return 'False'