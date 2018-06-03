########################################################
# DESCRIPTION:
# define the decorator app
#
# AUTHOR: ykx
# TIME: 2018.06.02
########################################################

#! /usr/bin/env python
# -*- coding:utf-8 -*-

from flask import Flask
from flask import request
 
app = Flask(__name__)

# change the imported module(.py file) to realize different functions of the decorator
from Web_Server import distribute
from Web_Server import handle
#from Web_Server import distribute2

