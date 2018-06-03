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

#from Web_Server import handle_upload
from Web_Server import app  # it means import the variable app from package app
from . import handle

from flask import request
# render_template() can import the files under the folder 'templates'
from flask import render_template

import json
import base64
import io
import numpy as np
import urllib

###################


@app.route('/upload/<file_id>/<file_size>', methods=['POST'])
def myupload(file_id, file_size):
    # if request.method == 'POST':
    #data = request.get_data()
    # print(data)
    #json_data = json.loads(data.decode("utf-8"))
    # print(json_data)
    return handle.upload(file_id, file_size)
    # else:
    #    data = request.get_data()
    #    print(data)
    #    return "get it"


###################

@app.route('/', methods=['GET', 'POST'])
def home():
    return render_template("index.html")


@app.route('/signin', methods=['POST'])
def signin():
    # 需要从request对象读取表单内容：
    if request.form['username'] == 'admin' and request.form['password'] == 'password':
        return '<h3>Hello, admin!</h3>'
    return '<h3>Bad username or password.</h3>'


@app.route('/user/<username>')
def show_user_profile(username):
    # show the user profile for that user
    return 'User %s' % username


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
# flask & json: https://blog.csdn.net/kl28978113/article/details/78648204
# flask & template: http://www.pythondoc.com/flask-mega-tutorial/templates.html
# flask request: https://www.cnblogs.com/wangjikun/p/6935592.html`

# Deployment Options: http://flask.pocoo.org/docs/1.0/deploying/#deployment
# Development Server: http://flask.pocoo.org/docs/1.0/server/#server
# url_for(): http://flask.pocoo.org/docs/1.0/api/#flask.url_for
