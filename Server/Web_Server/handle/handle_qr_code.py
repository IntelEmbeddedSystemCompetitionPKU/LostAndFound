import crypt
from Crypto.L
import uuid
import qrcode
import json

@app.route('/usr_qr_code', methods=['POST'])
# 得到附有个人信息的二维码(用户名，密码(MD5，用公钥加密))(Image)
def get_usr_qr_code():
    jdata = json.loads(request.data)
    print(jdata['name']+'with password '+jdata['passwd']+' wants a qrcode'+jdata['description'])
    username=jdata['name']
    passwd=jdata['passwd']
    description=jdata['description']
    try:
        r=c.execute('select * from User where username="'+username+'" and passwd="'+passwd+'";')
        if r==0:
            return 'False'
        qrcode = username+'#'+description+'#'+uuid.uuid1().__str__().replace('_','')
        c.execute('insert into User_qrcode values('+username+','+qrcode+');')
        # img=qrcode.make(qrcode)
        # img.save("E:/Some.png")
        return qrcode
        # return json.dumps({})
    except:
        return 'False'
