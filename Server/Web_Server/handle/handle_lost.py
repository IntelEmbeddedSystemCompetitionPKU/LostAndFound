from Web_Server import app

@app.route('/lost_list/<time_keywords>')
# 搜索失物的列表(时间，关键词)(UUID json list)
def lost_list(time_keywords):
    time_keywords_dict=time_keywords.split('_')
    print(time_keywords_dict)
    return 'list'


@app.route('/lost_sketch/<lost_uuid>')
# 得到失物的粗略信息(UUID)(低清图片，描述信息)
def show_post(lost_uuid):
    return '{"image":"image","description":"PKU_红色_校园卡"}'


@app.route('/lost_details/<lost_uuid>')
# 得到失物详细信息(UUID)(很多张高清图片)
def show_post(lost_uuid):
    return '{"images":["img1","img2","img3"]}'


@app.route('/qestion/<lost_uuid>')
# 失物填空题(UUID)(图片，几个空)
def qestion(lost_uuid):
    # show the subpath after /path/
    return '{"image":"img"}'


@app.route('/answer/<lost_uuid>')
# 用户的失物填空题结果(用户ID，UUID，json)(True, False)????
def answer(lost_uuid):
    return 'False'


@app.route('/lost_qrcode/<usrid>/<lost_uuid>')
# 得到指定失物的二维码(用户ID，UUID)(Image)
def lost_qrcode(lost_uuid):
    return 'lost_qrcode'
