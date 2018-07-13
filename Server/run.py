########################################################
# DESCRIPTION:
# (import app decorator from __init__.py)
# run the functions of the decorator 
# work as a script, run it by 'python3 run.py'
#
# AUTHOR: ykx
# TIME: 2018.06.02
########################################################

#!flask/bin/python
# -*- coding:utf-8 -*-


from Web_Server import app

# app.run(host='162.105.91.179')
# app.run(host='162.105.91.98', debug=True)
# app.run(host='10.128.171.216', debug=True)
app.run(host='192.168.1.103', debug=True)
