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
from Web_Server.settings import basepath,blank_img

# order by similarity
def sort_lost(lostlist,keyword):
    words=keyword.split(' ')
    keyword=keyword.replace(' ','')
    chars=[c for c in keyword if c.isalnum()]
    print('chars:',chars)
    l=[[r,sum([1 for word in words if word in r[1]]), sum([1 for char in chars if char in r[1]]) ] for r in lostlist]
    print(l)
    # l=[[r,sum([1 for word in words if word in r[1]]) ] for r in lostlist]
    l.sort(key=lambda x: -x[1]*100-x[2])
    lostlist=[e[0] for e in l if e[1]+e[2]>0]
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
    lostlist = mc.query_sql('select objuuid,description from Lost where ownername=%s and lostdate>=%s',(' ',date))
    if keyword!='':
        lostlist=sort_lost(lostlist,keyword)
    print(lostlist)
    return lostlist2json(lostlist)

@app.route('/query/lostlist/available/<username>', methods=['GET'])
def handle_query_available(username):
    lostlist=mc.query_sql('select objuuid from Lost where ownername=%s',(username))
    return lostlist2json(lostlist)

@app.route('/query/lostlist/notapplied/<username>', methods=['GET'])
def handle_query_notapplied(username):
    lostlist=mc.query_sql('select objuuid from Lost where ownername=%s and apply="0"',(username))
    return lostlist2json(lostlist)

@app.route('/query/getinfo/<uuid>', methods=['GET'])
def handle_query_getinfo(uuid):
    lostlist=mc.query_sql('select description,lostdate from Lost where objuuid=%s',(uuid))
    if len(lostlist)==0:
        return 'There is no such thing!'
    r=lostlist[0]
    ld_num = 1
    ldpath = basepath + uuid + '/LD'
    if os.path.exists(ldpath):
        ld_num=str(len(os.listdir(ldpath)))
    print(r)
    data = '{"description": "' + r[0] + '", "time": "' + r[1].isoformat()  + '", "LD_num": "' + str(ld_num) + '"}'
    print(data)
    return data


@app.route('/query/<uuid>/<picture_type>/<order>')
# uuid: uuid of object
# picture_type: LD, HD, mask
# order: 0, 1, 2, ...
def handle_query_LD(uuid, picture_type, order):
    path = basepath + uuid + '/' + picture_type + '/' + order + '.jpg'
    if os.path.exists(path) == False:
        print('There is no such thing named '+path)
        return send_file(blank_img,as_attachment=True)
    return send_file(path,as_attachment=True)


@app.route('/query/maskinfo/<uuid>', methods=['GET'])
def handle_query_maskinfo(uuid):
    path = basepath + uuid + '/data.txt'
    if os.path.exists(path) == False:
        return 'There is no such thing named '+path
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
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    fr = open(path + '/data.txt', 'rb')
    answer = json.loads(fr.read())
    len_sum,dis_sum = 0,0
    for item in json_data:
        itemjson = json.loads(json_data[item])
        for jtem in itemjson:
            # dis_sum+=dist(answer[item][jtem],itemjson[jtem])
            # len_sum+=len(answer[item][jtem])+len(itemjson[jtem])
            best_dis, best_len, high = 0, 0, 0
            for item_ans in answer:
                for jtem_ans in answer[item]:
                    dis = dist(answer[item_ans][jtem_ans],itemjson[jtem])
                    lth = len(answer[item_ans][jtem_ans])+len(itemjson[jtem])
                    rate = (dis+1)/(lth+1)
                    if rate > high:
                        best_dis, best_len, high =dis,lth,rate
            dis_sum+=best_dis
            len_sum+=best_len

    if (dis_sum+1)/(len_sum+1)<0.8:
        r=mc.nofetchall_sql('UPDATE Lost SET ownername=%s WHERE objuuid=%s',(username,objuuid))
        if r==0:
            print('oops! no such obj')
        mc.nofetchall_sql('UPDATE Lost SET apply="1" WHERE objuuid=%s',(objuuid))
        return 'True'
    else:
        return 'False'