#!/bin/python
import argparse
import requests
import os
import sys

parser = argparse.ArgumentParser(description='upload file')
parser.add_argument('-url',type=str,help='location url, must start with http',required=True)
parser.add_argument('-file',type=str,help='upload file location',required=True)
parser.add_argument('-cmd',type=str,help='command,-u means upload, -r means remove',required=True)
args = parser.parse_args()
if(args.cmd == 'r'):
    data = {'command':'remove','id':args.file}
    response = requests.post(args.url,data=data)
elif(args.cmd == 'u'):
    os.system('tar -czf ' + args.file + '.tar.gz ' + args.file)
    with open(args.file + '.tar.gz', 'rb') as f:
        data = {'command':'upload'}
        files = {'file':f}
        response = requests.post(args.url,data=data,files=files)
    print response.text
else:
    sys.exit('wrong command')
