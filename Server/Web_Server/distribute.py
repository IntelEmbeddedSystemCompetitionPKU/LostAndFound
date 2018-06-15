########################################################
# DESCRIPTION:
# sort queries and define different responses to them
# work like a head file
#
# AUTHOR: ykx
# TIME: 2018.06.02
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from Web_Server import app  # import the variable app from package 'Web_Server'
from . import handle # import package 'handle' from package 'Web_Server'

from flask import request
from flask import render_template # render_template() can import the files under the folder 'templates'

import json
#import base64
#import io
#import numpy as np
#import urllib

###################


#@app.route('/upload/<upload_type>', methods=['POST', 'GET'])
#def handle_upload(upload_type):
#    print(upload_type)
#    if request.method == 'POST':
#        data = request.get_data()
#        print(data)
#        json_data = json.loads(data.decode("utf-8"))
#        print(json_data)
#        if upload_type == 'HD':
#            return handle.upload_HD(json_data)
#        elif upload_type == 'LD':
#            return handle.upload_LD(json_data)
#        elif upload_type == 'mask':
#            return handle.upload_mask(json_data)
#        elif upload_type == 'information':
#            return handle.upload_information(json_data)
#        elif upload_type == 'description':
#            return handle.upload_description(json_data)
#        elif upload_type == 'fetchQues':
#            return handle.upload_fetchQues(json_data)
#        elif upload_type == 'result':
#            return handle.upload_result(json_data)

@app.route('/sign/<sign_type>', methods=['POST', 'GET'])
def handle_sign(sign_type):
    if request.method == 'POST':
        data = request.get_data()
        print(data)
        json_data = json.loads(data.decode("utf-8"))
        print(json_data)
        if sign_type == 'signup':
            return handle.sign_up(json_data)
        elif sign_type == 'signin':
            return handle.sign_in(json_data)

@app.route('/query/<query_type>/<keyword>', methods=['GET'])
def handle_query_get(query_type, keyword):
    if request.method == 'GET':
        if query_type == 'sketchyInfo':
            return handle.query_sketchyInfo(keyword)
        elif query_type == 'detailInfo':
            return handle.query_detailInfo(keyword)
        elif query_type == 'questions':
            return handle.query_questions(keyword)
        elif query_type == 'userGet':
            return handle.query_userGet(keyword)

@app.route('/query/<query_type>', methods=['POST'])
def handle_query_post(query_type):
    if request.method == 'POST':
        data = request.get_data()
        print(data)
        json_data = json.loads(data.decode("utf-8"))
        print(json_data)
        if query_type == 'userInfo':
            return handle.query_userInfo(json_data)
        elif query_type == 'lostList':
            return handle.query_userInfo(json_data)
        elif query_type == 'lostQR':
            return handle.query_lostQR(json_data)

###################

@app.route('/', methods=['GET', 'POST'])
def home():
    return render_template("index.html")

if __name__ == '__main__':
    app.run(host='192.168.31.228')


########
# ref  #
########
# flask quickstart chinese: http://docs.jinkan.org/docs/flask/quickstart.html
# flask render_template: https://blog.csdn.net/bestallen/article/details/52055061
# flask quickstart: http://flask.pocoo.org/docs/1.0/quickstart/
# flask api: http://flask.pocoo.org/docs/1.0/api/#flask.Flask
# flask & download: https://www.cnblogs.com/we8fans/p/7107353.html
# flask & json: https://blog.csdn.net/matengbing/article/details/78653591
# flask & json: https://blog.csdn.net/kl28978113/article/details/78648204
# flask & template: http://www.pythondoc.com/flask-mega-tutorial/templates.html
# flask request: https://www.cnblogs.com/wangjikun/p/6935592.html`

# Deployment Options: http://flask.pocoo.org/docs/1.0/deploying/#deployment
# Development Server: http://flask.pocoo.org/docs/1.0/server/#server
# url_for(): http://flask.pocoo.org/docs/1.0/api/#flask.url_for
