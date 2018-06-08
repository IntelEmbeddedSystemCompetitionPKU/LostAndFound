import crypt
from Crypto.L

@app.route('/usr_qr_code', methods=['POST'])
# 得到附有个人信息的二维码(用户名，密码(MD5，用公钥加密))(Image)
def get_usr_qr_code():
    jdata = json.loads(request.data)
    print(jdata['name']+'with password '+jdata['passwd']+' wants a qrcode'+jdata['description'])
    username=jdata['name']
    passwd=jdata['passwd']
    description=jdata['description']
    try:
        r=c.execute('select * from user where username="'+username+'" and passwd="'+passwd+'";')
        if r==0:
            return 'False'
        qrcode = username+'#'+
    except:
        return 'False'
    return 'qrcode_string'
