#!/bin/bash
# -*- coding:utf-8 -*-

#curl -X POST --data '{ "file":"aaef23asdfo2i3234"}' http://127.0.0.1:5000/upload/3342/231345
#curl -F "key=value" -F "filename=@.test.md" http://127.0.0.1:5000/upload/
#curl -X POST --data '{ "uuid":"aaef23asdfo2i3234", "HD": "MYHD"}' http://127.0.0.1:5000/upload/HD
#curl -X POST --data '{ "uuid":"aaef23asdfo2i3234", "HD": "MYHD"}' http://162.105.91.179:5000/query/lostlist
curl -X POST --data '{ "username":"fcg", "password": "MYHD"}' http://162.105.91.179:5000/sign/signup
curl -X POST --data '{ "username":"fcg", "password": "MYHD"}' http://162.105.91.179:5000/sign/signin
curl -X GET --data '{}' http://162.105.91.179:5000/query/5c946bd2292c4c658ca9e856746337d/LD/1
curl -X POST --data '{"test": "Can I compare thee to a summer''s day?"}' http://162.105.91.179:5000/query/qrcode
curl -X GET --data '{}' http://162.105.91.179:5000/query/maskinfo/5c946bd2292c4c658ca9e856746337d
10.2.15.121
curl -X POST --data '{ "username":"fcg", "targetuuid": "lilyuiid", "message":"u must give back!", "time":12345}' http://162.105.91.179:5000/upload/message
curl -X POST --data '{ "username":"fcg2"}' http://162.105.91.179:5000/query/noreplylist
curl -X POST --data '{ "username":"poorsoap", "targetuuid":"05924b5e7f9111e8ba66e4f89c86f5ba","time":123}' http://162.105.91.179:5000/query/messages
curl -X POST --data '{ "username":"fcg", "password": "MYHD"}' http://162.105.91.179:5000/query/qrcode_usr
curl -X POST --data '{ "username":"fcg", "password": "MYHD", "description":"my property!"}' http://10.1.173.3:5000/query/qrcode_usr

#curl -i -H "Content-Type:application/json" -X POST -d {\"uuid\":\"Alice\",\"HD\":\"MYHD\"} http://localhost:5000/upload/HD
#signup
#curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signup
#signin
#curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signin
# get lost list
#curl -i -H "Content-Type:application/json" http://localhost:5000/lost_list/20180520_20180521_校园卡_红色
