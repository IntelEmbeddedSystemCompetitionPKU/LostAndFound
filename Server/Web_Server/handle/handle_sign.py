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