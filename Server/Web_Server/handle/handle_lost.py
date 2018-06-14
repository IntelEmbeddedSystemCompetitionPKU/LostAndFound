from Web_Server import app
from flask import request
import json
import os
import pymysql

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
# date, keyword
def handle_query_lostlist():
    data = request.get_data()
    json_data = json.loads(data.decode('utf-8'))
    print(json_data)
    #time_keywords_dict=time_keywords.split('_')
    lostlist = query_mysql("objuuid", "Lost")
    print(lostlist)
    
    json_list = '{"uuid_num":' + str(len(lostlist)) + ','
    for k in range(0, len(lostlist)):
        json_list = json_list + '"uuid' + str(k) + '":' + lostlist[k][0] + ","
    json_list = json_list + "}"
    print(type(json_list))
    return(json_list.encode('utf-8'))

@app.route('/lost_sketch/<lost_uuid>')
# 得到失物的粗略信息(UUID)(低清图片，描述信息)
def show_post_sketch(lost_uuid):
    return '{"image":"image","description":"PKU_红色_校园卡"}'


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
