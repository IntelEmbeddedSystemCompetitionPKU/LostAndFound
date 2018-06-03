# LostAndFound
Let's do that.
## TCP
### cmd:upload
* id:文件名
* size:文件大小
* data:data,tar.gz
#### detail
* 高清原图abc.jpg，打码的高清图片abc_mask.jpg，打码压缩的图片abc_low_mask.jpg，block文件abc_block.txt
* {0；坐标；识别内容}
* {1；坐标；识别内容}
* {2；坐标；识别内容}

### cmd:remove
* id:文件名
### cmd:keywordsearch
* key:关键字
* date:日期
* range:0:20//20:40
* return-
* img:低清图片
* date:放置日期
* id:id if empty,

### cmd:detailsearch
* id:id
* return-
* img:高清
* blockcounter:

### cmd:identify
* id:id
* blocks:"0:xxxxx;1:xxxxx;...."
* return-
* result:true/false
* qrcode:二维码(文件名)


# 功能
## 远程还物
放东西：
when 没有标签
文字识别(OK)->能不能直接让拾到人输入简单特征（打字？语音输入？打字）先打字
when 有标签
直接扫标签(OK)->发送推送
optional
个人信息：可选？留下沟通用的微信二维码/APP个人识别码()
亮点？

取物品：
留下面部信息（需要无遮挡）(face++ API or Local?)
扫描二维码，用公钥解密得到UUID，再调用相应脚本(OK)
亮点？

发布：
在APP上，填空(Half App)，申请人工(仿微信)
人工申请，通过公众号匿名联系(在APP里其实可以更简单一些)
亮点？

机械结构：
提高空间利用率
远程操控
亮点？
# 要求
进度不够快，要赶一些
后面一个月赶进度
要做PPT，能做多少做多少
## 答辩要求
参考以前的ppt


## 服务器API需求
### 手机
1. 注册(用户名，密码(MD5，用公钥加密))(True,False)
2. 登陆(用户名，密码(MD5，用公钥加密))(True,False)
3. 得到附有个人信息的二维码(用户名，密码(MD5，用公钥加密))(Image)
4. 搜索失物的列表(时间，关键词)(UUID json list)
5. 得到失物的粗略信息(UUID)(低清图片，描述信息)
5. 得到失物详细信息(UUID)(很多张高清图片)
6. 得到失物填空题(UUID)(图片，几个空)
7. 发送失物填空题结果(用户ID，UUID，json)(True, False)
8. 得到指定失物的二维码(用户ID，UUID)(Image)
9. 得到领取失物列表(用户ID)(json)
10. 聊天(放置)
### 板子
1. 发送失物信息(图片，描述，填空题，UUID)()
2. 发送失物信息描述(时间，描述，UUID)
3. 发送失物低清图片(图片，UUID)
4. 发送失物高清图片(图片，UUID)
5. 发送失物打码图片(图片，json，UUID)
6. 发送领取照片(图片，时间，UUID)
7. 发送有登记二维码(时间，UUID)
