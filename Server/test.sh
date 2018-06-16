#!/bin/bash
# -*- coding:utf-8 -*-

#curl -X POST --data '{ "file":"aaef23asdfo2i3234"}' http://127.0.0.1:5000/upload/3342/231345
#curl -F "key=value" -F "filename=@.test.md" http://127.0.0.1:5000/upload/
#curl -X POST --data '{ "uuid":"aaef23asdfo2i3234", "HD": "MYHD"}' http://127.0.0.1:5000/upload/HD
#curl -X POST --data '{ "uuid":"aaef23asdfo2i3234", "HD": "MYHD"}' http://162.105.91.179:5000/query/lostlist
#curl -X POST --data '{ "name":"aaef23asdfo2i3234", "passwd": "MYHD"}' http://162.105.91.179:5000/sign/signup
curl -X POST --data '{ "name":"aaef23asdfo2i3234", "passwd": "MYHD"}' http://162.105.91.179:5000/sign/signin
curl -X GET --data '{}' http://162.105.91.179:5000/query/5c946bd2292c4c658ca9e856746337d/LD/1






#curl -i -H "Content-Type:application/json" -X POST -d {\"uuid\":\"Alice\",\"HD\":\"MYHD\"} http://localhost:5000/upload/HD
#signup
#curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signup
#signin
#curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signin
# get lost list
#curl -i -H "Content-Type:application/json" http://localhost:5000/lost_list/20180520_20180521_校园卡_红色
