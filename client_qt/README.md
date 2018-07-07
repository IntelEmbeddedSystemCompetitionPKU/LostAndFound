# Qt_part
## interact
interact with users
### store
for the one who found lost things
#### card
* 2 photos
#### wallet
* 1 photo for wallet
* 2n photos for cards in it
#### other objects
* n photos from different angles
#### todo(qml)
- [x] qt camera control
- [ ] a list to show photos and ocr result(delete)
- [x] decode qrcode via camera
- [ ] use scripts from fcg
- [x] uuid name for project
## upload
### tar.gz
tar.gz all the photos and ocr results
### http
upload tar file via http
### todo
- [x] python 'Requests'
- [ ] qt process
- [x] post data via python
- [x] post remove via python
## database
this is used to store information which is still in chest
### xml
uuid-location
### todo
- [ ] Qxml




# Python 接口 fcg
## Classify and OCR
### 输入
图片文件路径(1.jpg)
### 返回值
* 0: 处理过程没有问题
* -1: 有问题
### 处理结果
同一文件夹下的JSON文本(1.txt)
#### 格式(带-的为可选项)
* kind: string
* - blank_num: int
* - blank_<num>: string

## 人脸识别
### 输入
图片文件路径
### 返回值
* 0: 有人脸
* -1:没有人脸

