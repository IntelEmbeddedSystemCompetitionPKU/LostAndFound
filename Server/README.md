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
> 3. 标记有`*`表示功能基本完成能ping/pong

## 1.1 注册

1. 请求

    url: `http://<ip>:<port>/sign/signup`
    
    method: POST
    
    body: {"username": <username>, "password": <password>} 

2. 返回值

   1(True)/0(False)

## 1.2 登录

1. 请求

   url: `http://<ip>:<port>/sign/signin`
   
   method: POST
   
   body: {"username": <username>, "password": <password>} 

2. 返回值

   1/0

## 1.3 获取用户信息二维码

1. 请求

   url: `http://<ip>:<port>/query/userQR`
   
   method: POST
   
   body: {"username": <username>, "password": <password>} 

2. 返回值

   image

## 1.4 获取失物列表 *

1. 请求

   url: `http://<ip>:<port>/query/lostlist`
   
   method: POST
   
   body: {"description": <description>, "date": <date>} 

2. 返回值

   body: {"uuid_num": <uuid_num>, "uuid1": <uuid>, "uuid2": <uuid>, ...}

## 1.5 查询失物粗略信息

1. 请求

   url: `http://<ip>:<port>/query/sketchyInfo/<uuid>`
   
   method: GET
   
2. 返回值

   json

## 1.6 查询失物详细信息

1. 请求

   url: `http://<ip>:<port>/query/DetailInfo/<uuid>`
   
   method: GET
   
2. 返回值

   json

## 1.7 查询失物验证填空题

1. 请求

   url: `http://<ip>:<port>/query/questions/<uuid>`
   
   method: GET
   
2. 返回值

   json

## 1.8 发送事物填空题结果

1. 请求

   url: `http://<ip>:<port>/upload/results`
   
   method: POST
   
   body: {"num_block": <num_block>, "block1": <block1>, "block2": <block2>, ...}

2. 返回值

   1(True)/0(False or Error)

## 1.9 获取指定失物二维码

1. 请求

   url: `http://<ip>:<port>/query/lostQR`
   
   method: POST
   
   body: {"userID": <userID>, "uuid": <uuid>}

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

## 2.1 发送失物信息

1. 请求

   url: `http://<ip>:<port>/upload/information`

   method: POST

   body: {"uuid": <uuid>, "description": <description>, "time": <time>}

2. 返回值

   1(succeed)


## 2.2 发送失物低清图（LD）

1. 请求

   url: `http://<ip>:<port>/upload/LD`
   
   method: POST
   
   body: {"uuid": <uuid>, "LD_num": <num>, "LD1": <picture>, "LD2": <picture>, ...}

2. 返回值

   1/0(there is no filepath for that uuid)

## 2.3 发送失物高清图（HD）

1. 请求

   url: `http://<ip>:<port>/upload/HD`
   
   method: POST
   
   body: {"uuid": <uuid>, "HD_num": <num>, "HD1": <picture>, "HD2": <picture>, ...}

2. 返回值
  
   1/0(there is no filepath for that uuid)

## 2.4 发送失物打码图（mask）

1. 请求

   url: `http://<ip>:<port>/upload/mask`

   method: POST

   body: {"uuid": <uuid>, "mask_num": <num>, "mask1":{"picture": <picture>, "block_num": <num>, "block1": <block>, "block2": <block>, ...}, "mask2":{...}, ... }

2. 返回值

   1/0


## 2.5 发送领取图片（fetch）

1. 请求

   url: `http://<ip>:<port>/upload/fetch`
   
   method: POST
   
   body: {"uuid": <uuid>, "fetch_num": <num>, "fetch1": <picture>, "fetch2": <picture>, ...}

2. 返回值

   1/0

## 2.6 发送有登记二维码

waiting...

## 2.7 发送完整压缩文件 *

1. 请求

   url: `http://<ip>:<port>/upload/compress/<uuid>`

   method: POST

   body: {"file": <file>]}

2. 返回值

   1/0(the uuid exists)

3. 压缩内容

   ~~~
   //compress.tar.gz
   .
   └── uuid
       ├── data.txt
       ├── fetch
       ├── HD
       │   ├── picture1.jpg
       │   └── picture2.jpg
       ├── LD
       │   ├── picture1.jpg
       │   └── picture2.jpg
       └── mask
           ├── picture1.jpg
           └── picture2.jpg
   ~~~

   ~~~
   //data.txt
   {
       "uuid": <uuid>,
       "description": <description>,
       "date": <date>,  //上交失物时间
       "LD_num": <LD_num>,  //低清图数量
       "HD_num": <HD_num>,  //高清图数量
       "mask_num": <mask_num>,  //打码图数量
       "mask": {
           mask1":{
               "block_num": <block_num>,  //打码图1中block数量
               "block1": <block>,    //打码图1中block1内容
               "block2": <block>,
               ...
           }
           "mask2":{
               "block2": <block>,
               "block2": <block>,
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
|  |-upload_HD(json_data) -> 2.4
|  |-upload_LD(json_data) -> 2.3
|  |-upload_mask(json_data) -> 2.5
|  |-upload_information(json_data) -> 2.1
|  |-upload_fetch(json_data) -> 2.6
|  |-upload_results(json_data) -> 1.8 
|-sign.py
|  |
|  |-sign_up(json_data) -> 1.1
|  |-sign_in(json_data) -> 1.2
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

