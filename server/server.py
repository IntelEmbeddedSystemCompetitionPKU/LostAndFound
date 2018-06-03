########################################################
# DESCRIPTION:
# (import app decorator from __init__.py)
# sort queries and define different responses to them
# work like a head file
#
# AUTHOR: ykx
# TIME: 2018.06.02
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-
from flask import Flask
from flask import request
from flask import render_template
import json
app = Flask(__name__)
###################


@app.route('/upload/')
def upload():
    return


###################

@app.route('/', methods=['GET', 'POST'])
def home():
    return render_template("index.html")


@app.route('/signup', methods=['POST'])
# 注册(用户名，密码(MD5，用公钥加密))(True,False)
def signup():
    jdata = json.loads(request.data)
    print(jdata['name']+' trys to sign up with password '+jdata['passwd'])
    #若不冲突且合法则存入数据库
    return 'True'


@app.route('/signin', methods=['POST'])
# 登陆(用户名，密码(MD5，用公钥加密))(True,False)
def signin():
    jdata = json.loads(request.data)
    print(jdata['name']+' trys to login with password '+jdata['passwd'])
    # 在数据库中查询用户
    return 'False'


@app.route('/usr_qr_code', methods=['POST'])
# 得到附有个人信息的二维码(用户名，密码(MD5，用公钥加密))(Image)
def get_usr_qr_code():
    jdata = json.loads(request.data)
    print(jdata['name']+' trys to login with password '+jdata['passwd'])
    return 'qrcode_string'


@app.route('/lost_list<time_keywords>')
# 搜索失物的列表(时间，关键词)(UUID json list)
def lost_list(time_keywords):
    print(type(time_keywords))
    print(time_keywords)
    return 'list'


@app.route('/post/<int:post_id>')
def show_post(post_id):
    # show the post with the given id, the id is an integer
    return 'Post %d' % post_id


@app.route('/path/<path:subpath>')
def show_subpath(subpath):
    # show the subpath after /path/
    return 'Subpath %s' % subpath


if __name__ == '__main__':
    app.run()


########
# ref  #
########
# flask quickstart chinese: http://docs.jinkan.org/docs/flask/quickstart.html
# flask render_template: https://blog.csdn.net/bestallen/article/details/52055061
# flask quickstart: http://flask.pocoo.org/docs/1.0/quickstart/
# flask api: http://flask.pocoo.org/docs/1.0/api/#flask.Flask
# flask & download: https://www.cnblogs.com/we8fans/p/7107353.html
# flask & json: https://blog.csdn.net/matengbing/article/details/78653591
# flask & template: http://www.pythondoc.com/flask-mega-tutorial/templates.html
# flask request: https://www.cnblogs.com/wangjikun/p/6935592.html`

# Deployment Options: http://flask.pocoo.org/docs/1.0/deploying/#deployment
# Development Server: http://flask.pocoo.org/docs/1.0/server/#server
# url_for(): http://flask.pocoo.org/docs/1.0/api/#flask.url_for

