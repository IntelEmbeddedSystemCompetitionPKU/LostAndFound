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
app.run(host='10.1.173.3', debug=True)
