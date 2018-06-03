#!/bin/bash
# -*- coding:utf-8 -*-

#curl -X POST --data '{ "file":"aaef23asdfo2i3234"}' http://127.0.0.1:5000/upload/3342/231345
curl -F "key=value" -F "filename=@test.md" http://127.0.0.1:5000/upload/3342/231345
