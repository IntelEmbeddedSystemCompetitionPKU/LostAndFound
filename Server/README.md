# API(for YQL)

> 1. \< \>表示变量
>
>
> 2. 命令与url的映射关系(详见后面各命令)：
>
>    注册/登录 -> sign
>
>    获取... -> query(POST)
>
>    查询... -> query(GET)
>
>    发送... -> upload
>
>
> 3. 标记有`*`表示功能基本完成能ping/pong，标记有`?`表示本地未见bug但不知远程调用情况



| 请求                         | url                                     | method | 上传内容                                         | 返回值                                                       | state |
| ---------------------------- | --------------------------------------- | ------ | ------------------------------------------------ | ------------------------------------------------------------ |---|
| 1.1 注册                     | /sign/signup                            | POST   | {"username": <username>, "password": <password>} | 'True'/'False'                                               | done |
| 1.2 登录                     | /sign/signin                            | POST   | {"username": <username>, "password": <password>} | 'True'/'False'                                               | done |
| 1.3 获取失物列表             | /query/lostlist                         | POST   | {"description": <description>, "date": <date>}   | {"uuid_num": <num>, "uuid0": <uuid>, "uuid1": <uuid>, ...}   | tested |
| 1.4 获取物品粗略信息         | /query/getinfo/\<uuid>                  | GET    | /                                                | {"description": <description>, "date", <date> "LD_num": <num>}| done |
| 1.5 获取图片                 | /query/\<uuid>/\<picture_type>/\<order> | GET    | /                                                | **file**(picture)                                            | done |
| 1.6 获取物品所有mask基本信息 | /query/maskinfo/\<uuid>                 | GET    | /                                                | {"mask_num":<num>, "block0_num":<num>, "block1_num":<num>, ...}  | not done |
| 1.7 验证mask信息             | /query/maskcheck/\<uuid>                | GET    | /                                                | 'True'/'False'                                               | notdone |
| 1.8 获取用户信息二维码       | /query/qrcode_user                      | POST   | {"username": <username>, "password": <password>} | **file**(image)                                              | done |
| 1.9 获取指定失物二维码       | /query/qrcode_lost                      | POST   | {"useruuid": <useruuid>, "itemuuid": <itemuuid>} | **file**(image)                                              | done |
| 2.1 发送完整压缩文件         | /upload/compress/\<uuid>                | POST   | {"file": <file>}                                 | 'True'/'False'                                               | not done |
| 3.1 获取防丢二维码           | /query/qrcode_anti                      | POST   | {"username": <username>, "password": <password>， "description":<description>} | **file**(image)                | done |
| 3.2 获取从未获取过二维码的物品列表| /query/noobatinlist                | POST   | {"username": <username>}                         | "uuid_num": <num>, "uuid0": <uuid0> ...                      | not done|
| 4.1 发送消息给指定用户       | /upload/message                         | POST   | {"username": <username>, "targetuuid": <targetuuid>, "message": <message>, "time": <time>}| "True"/" False" | not done|
| 4.2 获取从某时刻起的指定用户消息| /query/messages                      | POST   | {"username": <username>, "targetuuid": <targetuuid>, "time": <time>} |"message_num":<num>,"message0":<message_0>,"time_0":<time_0>...| not done|
| 4.3 获取从未回复过的用户列表 | /query/noreplaylist                     | POST   | {"username": <username>}                          | "user_num":<num>,"user0":<user_0>,"user1":<user_1>...| not done |





## 1.1 注册 *

1. 请求

    url: `http://<ip>:<port>/sign/signup`

    method: POST

    body: {"username": <username>, "password": <password>}

2. 返回值

   'True'/'False'

## 1.2 登录 *

1. 请求

   url: `http://<ip>:<port>/sign/signin`

   method: POST

   body: {"username": <username>, "password": <password>}

2. 返回值

   'True'/'False'

## 1.3 获取失物列表 *

1. 请求

   url: `http://<ip>:<port>/query/lostlist`

   method: POST

   body: {"description": <description>, "date": <date>}

2. 返回值

   body: {"uuid_num": <uuid_num>, "uuid0": <uuid>, "uuid1": <uuid>, ...}

## 1.4 获取物品粗略信息 *

1. 请求

   url: `http://<ip>:<port>/query/getinfo/<uuid>`

   method: GET

2. 返回值

    str({"description": <description>, "date", <date> "LD_num": <num>})

## 1.5 获取图片 *

1. 请求

   url: `http://<ip>:<port>/query/<uuid>/<picture_type>/<order>`

   method: GET

2. 返回值

    file(picture)

## 1.6 获取物品所有mask基本信息 *

1. 请求

   url: `http://<ip>:<port>/query/maskinfo/<uuid>`

   method: GET

2. 返回值

    str({"mask_num", "block0_num", "block1_num", ...})

## 1.7 验证mask信息 ?

1. 请求

   url: `http://<ip>:<port>/query/maskcheck/<uuid>`

   method: GET

2. 返回值

    'True'

## 1.8 获取用户信息二维码 ?

1. 请求

   url: `http://<ip>:<port>/query/qrcode`

   method: POST

   body: {"username": <username>, "password": <password>}

2. 返回值

   image

## 1.9 获取指定失物二维码 ?

1. 请求

   url: `http://<ip>:<port>/query/qrcode`

   method: POST

   body: {"useruuid": <useruuid>, "itemuuid": <itemuuid>}

2. 返回值

   image

## 1.10 获取已领取失物列表

1. 请求

   url: `http://<ip>:<port>/query/userGetList`

   method: GET

2. 返回值

   json

## 1.11 聊天

waiting...

## 2.0 发送完整压缩文件 *

1. 请求

   url: `http://<ip>:<port>/upload/compress/<uuid>`

   method: POST

   body: {"file": <file>]}

2. 返回值

   'True'/'False'(the uuid exists)

3. 压缩内容

   ~~~
   //compress.tar.gz
   .
   └── uuid
       ├── data.txt
       ├── fetch
       ├── HD
       │   ├── picture0.jpg
       │   └── picture1.jpg
       ├── LD
       │   ├── picture0.jpg
       │   └── picture1.jpg
       └── mask
           ├── picture0.jpg
           └── picture1.jpg
   ~~~

   ~~~
   //data.txt
   {
       "uuid": <uuid>,
       "description": <description>,
       "time": <time>,  //上交失物时间
       "LD_num": <LD_num>,  //低清图数量
       "HD_num": <HD_num>,  //高清图数量
       "mask_num": <mask_num>,  //打码图数量
       "mask": {
           "mask0":{
               "block_num": <block_num>,  //打码图1中block数量
               "block0": <block>,    //打码图1中block1内容
               "block1": <block>,
               ...
           }
           "mask1":{
               "block0": <block>,
               "block1": <block>,
               ...
           }
           ...
           "mask*":{...}  //打码图n
       }
       "fetch_num": <fetch_num>  //取物成功后上传图数量
   }
   ~~~




# Codes(for FCG)

~~~
# Tree for the package 'Web_Server'

__init__.py(import distribute.py & 'handle' package)
distribute.py(differ by url)
handle(package)
|
|-__init__.py
|-upload.py
|  |
|  |-handle_upload_compress(uuid) -> 2.7
|-sign.py
|  |
|  |-handle_sign_up() -> 1.1
|  |-handle_sign_in() -> 1.2
|-query.py
   |
   |-query_sketchyInfo(uuid) -> 1.5
   |-query_detailInfo(uuid) -> 1.6
   |-query_questions(uuid) -> 1.7
   |-query_userGetList(userID) -> 1.10
   |-query_userQR(json_data) -> 1.3
   |-query_lostList(json_data) -> 1.4
   |-query_lostQR(json_data) -> 1.9
~~~



Rules:

0. json中所有key的value都是字符串

1. 如果要在handle包已有的.py文件中增加函数，只需要在添加好函数之后，在上层的distribute.py中添加对应的装饰器，装饰器用到该函数时调用方式是`handle.<function_name>`
2. 如果要在handle包里新建一个.py文件，需要先在handle的`__init__.py`里面添加`from .<name>.py import *`，其次在distribute.py里面添加对应的装饰器，装饰器用到该函数时调用方式是`handle.<function_name>`
