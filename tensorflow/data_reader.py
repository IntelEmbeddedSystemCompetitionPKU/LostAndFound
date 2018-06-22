
# coding: utf-8

# In[21]:


import numpy as np
import math
import random

class data_reader:
    'This class is used to read data from npy file, which has been normalized'
    data = []
    img_number = []
    width = 0
    height = 0
    channel = 0
    class_number = 0
    
    def __init__(self, npyfiles):
        self.class_number = len(npyfiles)
        for i in range(self.class_number):
            filedata = np.load(npyfiles[i])
            self.img_number.append(np.shape(filedata)[0])
            self.data.append(filedata)
        self.width = np.shape(self.data[0])[1]
        self.height = np.shape(self.data[0])[2]
        self.channel = np.shape(self.data[0])[3]
    
    def get_batch(self,batch_size):
        output_data = np.zeros([batch_size, self.height, self.width, self.channel])
        output_label = np.zeros([batch_size, self.class_number])
        for i in range(batch_size):
            select_class = int(math.floor(random.random() * self.class_number))
            output_label[i, select_class] = 1
            select_index = int(math.floor(random.random() * self.img_number[select_class]))
            output_data[i] = self.data[select_class][select_index]
        return output_data, output_label
    

