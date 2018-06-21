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

basepath = '/home/ykx/Server_File/'

#################
## Query MySQL ##
#################

def query_mysql(contents, table):
    conn = pymysql.connect("localhost", user='root', passwd='ykx970910', db='LostFound', charset='utf8')
    cursor = conn.cursor()
    cursor.execute("SELECT " + contents + " FROM " + table)
    results = cursor.fetchall() # type(results) == tuple
    conn.commit()
    cursor.close()
    conn.close()
    return results

@app.route('/query/lostlist', methods=['POST'])
# description, date
def handle_query_lostlist():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))
    print(json_data)
    #time_keywords_dict=time_keywords.split('_')
    lostlist = query_mysql("objuuid", "Lost")
    print(lostlist)

    json_list = '{"uuid_num": "' + str(len(lostlist)) + '"'
    for k in range(0, len(lostlist)):
        json_list = json_list + ',"uuid' + str(k) + '": "' + lostlist[k][0] + '"'
    json_list = json_list + "}"
    print(type(json_list))
    return(json_list.encode('utf-8'))

# !!! need to modify !!!
@app.route('/query/getinfo/<uuid>', methods=['GET'])
def handle_query_getinfo(uuid):
    path = basepath + uuid
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    fr = open(path + '/data.txt', 'r')
    data = fr.read()
    print(data)
    jdata = json.loads(data)
    print(jdata)
    response = '{"description": "' + jdata['description'] + '", "time": "' + jdata['time'] + '", "LD_num": "' + jdata['LD_num'] + '"}'
    print(response)
    fr.close()
    return response

@app.route('/query/<uuid>/<picture_type>/<order>')
# uuid: uuid of object
# picture_type: LD, HD, mask
# order: 0, 1, 2, ...
def handle_query_LD(uuid, picture_type, order):
    print(uuid, picture_type, order)
    path = basepath + uuid
    print(path)
    if os.path.exists(path) == False:
        return 'There is no such thing!'
    #picture = path + '/' + picture_type + '/' + picture_type + order + '.jpg'
    picture_dir = picture_type + order + '.jpg'
    #img = open(picture, 'rb')
    #resp = make_response(img, mimetype='image/jpg')
    directory = path + '/' + picture_type + '/'
    return send_from_directory(directory, picture_dir, as_attachment=True)

    #fr = open(picture, 'rb')
    #img = fr.read()
    #img64 = {"img": img}
    #img64 = json.dumps(img64)
    #img64 = base64.b64encode(img)
    #files = {'file': open(picture, 'rb')}
    #print(type(files))
    return img64

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

    return 'True'
    #mask_num = int(answer['mask_num'])
    #for k in range(0, mask_num):
    #    if (json_data['mask'] != answer['mask']):
    #        return 'False'
    #    else:
    #        return 'True'



#############################
#############################
@app.route('/lost_details/<lost_uuid>')
# 得到失物详细信息(UUID)(很多张高清图片)
def show_post(lost_uuid):
    return '{"images":["img1","img2","img3"]}'


@app.route('/qestion/<lost_uuid>')
# 失物填空题(UUID)(图片，几个空)
def qestion(lost_uuid):
    # show the subpath after /path/
    return '{"image":"img"}'


@app.route('/answer/<lost_uuid>')
# 用户的失物填空题结果(用户ID，UUID，json)(True, False)????
def answer(lost_uuid):
    return 'False'


@app.route('/lost_qrcode/<usrid>/<lost_uuid>')
# 得到指定失物的二维码(用户ID，UUID)(Image)
def lost_qrcode(lost_uuid):
    return 'lost_qrcode'
