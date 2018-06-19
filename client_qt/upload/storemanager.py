import json
import os

def init_log():
    logdir = '/home/upsquared/workspace/data/log.json'
    if not os.path.exists(logdir):
        
