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
curl -X POST --data '{ "username":"poorsoap", "targetuuid": "objobjuuid", "message":"u must give back!", "time":12345}' http://10.128.171.216:5000/upload/message
curl -X POST --data '{ "username":"fcgfcg"}' http://10.128.171.216:5000/query/noreplylist
curl -X POST --data '{ "username":"poorsoap", "targetuuid":"objobjuuid","time":123}' http://10.128.171.216:5000/query/messages
curl -X POST --data '{ "username":"fcg", "password": "MYHD"}' http://162.105.91.179:5000/query/qrcode_usr
curl -X POST --data '{ "username":"fcg", "password": "MYHD", "description":"my property!"}' http://10.1.173.3:5000/query/qrcode_usr

insert into Lost(objuuid,lostdate,description,ocr,finderuuid,owneruuid) values('obj0','20180706','a cup','cup cup', 'finder1','');
insert into Lost(objuuid,lostdate,description,ocr,finderuuid,owneruuid) values('obj1','20180707','a card','card cup', '','');
insert into Lost(objuuid,lostdate,description,ocr,finderuuid,owneruuid) values('obj2','20180707','a wallet','money is bad', '','owner1');
curl -X POST --data '{ "description":"cup", "date": "20180706"}' http://10.1.178.226:5000/query/lostlist
curl -X GET http://10.1.178.226:5000/query/lostlist/available/owner1
curl -X GET http://10.1.178.226:5000/query/lostlist/notapplied/owner1
curl -X POST --data '{"useruuid":"owner1" , "itemuuid":"obj2" }' http://10.1.178.226:5000/query/qrcode_lost

#curl -i -H "Content-Type:application/json" -X POST -d {\"uuid\":\"Alice\",\"HD\":\"MYHD\"} http://localhost:5000/upload/HD
#signup
#curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signup
#signin
#curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signin
# get lost list
#curl -i -H "Content-Type:application/json" http://localhost:5000/lost_list/20180520_20180521_校园卡_红色

insert into Lost(objuuid,lostdate,description) values("358e18ec48c3488e8d2942b935ac170d","2018-07-07","kind;kind;kind;");
insert into Lost(objuuid,lostdate,description) values("a5ec5ff7d37a4bf0a4bcee4eac068c86","2018-07-07","kind;kind;kind;");
insert into Lost(objuuid,lostdate,description) values("edc13b28d2614517b8f9e2319ba9f4ea","2018-07-07","kind;kind;");

insert into User(username,password,useruuid) values("poorsoap","testing","e7c9bd68825211e88eb28cec4b7078bd");
curl -X GET http://10.1.172.209:5000/query/getinfo/a5ec5ff7d37a4bf0a4bcee4eac068c86
curl -X GET http://10.1.172.209:5000/query/edc13b28d2614517b8f9e2319ba9f4ea/LD/0
curl -X GET http://10.1.172.209:5000/query/maskinfo/358e18ec48c3488e8d2942b935ac170d

curl -X POST --data  '{'mask0': '{"blank0":"jgg","blank1":"hhh","blank2":""}', 'mask1': '{"blank0":"hh"}'} http://10.1.172.209:5000/query/maskcheck/poorsoap/358e18ec48c3488e8d2942b935ac170d
