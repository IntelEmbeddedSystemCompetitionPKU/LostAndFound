@app.route('/usr_qr_code', methods=['POST'])
# 得到附有个人信息的二维码(用户名，密码(MD5，用公钥加密))(Image)
def get_usr_qr_code():
    jdata = json.loads(request.data)
    print(jdata['name']+' trys to login with password '+jdata['passwd'])
    return 'qrcode_string'