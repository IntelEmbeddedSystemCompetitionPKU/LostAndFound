from flask import request
import json
import os
#import base64


def upload_HD(data):
    print(data['uuid'])
    print(data)
    return ("uuid: " + data['uuid'] + "HD: " + data['HD'])
