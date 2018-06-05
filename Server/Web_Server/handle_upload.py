########################################################
# DESCRIPTION:
# handle functions about uploading files
#
# AUTHOR: ykx
# TIME: 2018.06.04
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from Web_Server import app
from flask import request
import json
import os

# terminal mechine
@app.route('/upload/HD', methods=['POST'])
def handle_upload_HD():
    data = request.get_data()
    print(data)
    
    json_data = json.loads(data.decode('utf-8'))
    print(json_data)
    
    return ("picture: " + json_data["picture"] + "uuid: " + json_data["uuid"])

@app.route('/upload/LD', methods=['POST'])
def handle_upload_LD():

