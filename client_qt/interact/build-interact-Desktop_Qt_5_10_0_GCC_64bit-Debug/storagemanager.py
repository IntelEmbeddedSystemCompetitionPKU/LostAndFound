
# coding: utf-8

# In[16]:


import json
import os
import numpy as np

configdir = './storage.config'
# incase there isn't config file at all
def init_config():
    if not os.path.exists(configdir):
        try:
            os.mkdir(os.path.split(configdir)[0])
        except OSError:
            print('config dir exists')
        with open(configdir, 'w') as f:
                config_dict = {'logdir':'./storage/log.json'}
                json.dump(config_dict, f)


# In[20]:


def load_config():
    init_config()
    with open(configdir) as f:
        config = json.load(f)
    return config


# In[21]:


# incase there isn't log file at all
def init_log():
    logdir = load_config()
    logdir = logdir['logdir']
    if not os.path.exists(logdir):
        try:
            os.mkdir(os.path.split(logdir)[0])
        except:
            print('log dir exists')
        with open(logdir, 'w') as f:
            log_dict = {'max_num':20}
            json.dump(log_dict, f)


# In[42]:


def load_log():
    init_log()
    logdir = load_config()
    with open(logdir['logdir']) as f:
        log = json.load(f)
    return log

def save_log(input_dict):
    init_log()
    logdir = load_config()
    with open(logdir['logdir'], 'w') as f:
        json.dump(input_dict, f)


# In[43]:


# main interface for saving item
# return a number for the free loaction, -1 means no space
def save_item(inputuuid):
    log = load_log()
    if len(log) > log['max_num']:
        return -1
    else:
        bitmap = np.zeros(log['max_num'] + 1)
        for key in log.keys():
            bitmap[log[key]] = 1
        for i in range(log['max_num']):
            if bitmap[i] == 0:
                log[inputuuid] = i
                save_log(log)
                return i


# In[48]:


# main interface for removing item from log file
# return location for existing item, -1 for null
def remove_item(inputuuid):
    log = load_log()
    if inputuuid in log:
        location = log[inputuuid]
        log.pop(inputuuid)
        save_log(log)
        return location
    return -1


# In[51]:
def is_exist(inputuuid):
    log = load_log()
    if inputuuid in log:
        return True
    else:
        return False

