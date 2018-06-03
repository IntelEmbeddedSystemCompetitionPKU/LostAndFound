from flask import request
import json
import os
#import base64

def upload(file_id, file_size):
    upload_file = request.files['file']
    base_path = os.path.dirname(__file__)
    upload_path = os.path.join(base_path, 'static/uploads', secure_filename(upload_file.filename))
    upload_file.save(upload_path)

#    data = request.get_data()
#    print(data)
    
    # first decode from utf-8 to str
    # second transfer from str to json
#    json_data = json.loads(data.decode('utf-8'))
#    print(json_data)
    
#    return ("id: " + json_data["file"])
    return ("id: " + file_id + "size: " + file_size)
# json.dumps & json.loads: https://blog.csdn.net/mr_evanchen/article/details/77879967
