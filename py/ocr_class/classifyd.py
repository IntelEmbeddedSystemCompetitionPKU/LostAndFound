from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
#mvNCCompile reconstructed.meta -s 12 -in train/input -on train/output -o ./ncsk_graph/inference.graph
import argparse
import sys
import tempfile
from mvnc import mvncapi
import numpy as np
from tensorflow.examples.tutorials.mnist import input_data
import cv2
import tensorflow as tf
import time
import signal
import os


FLAGS = None
kinds=['card','key','phone','wallet','other']
width = 224
height = 224


t1 = time.time()
# Open a device
device_list = mvncapi.EnumerateDevices()
device = mvncapi.Device(device_list[0])
device.OpenDevice()
# Load a graph from file at some GRAPH_FILEPATH
GRAPH_FILEPATH = '/home/upsquared/py/ocr_class/ncsk_graph/inference.graph'
with open(GRAPH_FILEPATH, mode='rb') as f:
    graph_buffer = f.read()
# Allocate the graph to the device
graph = device.AllocateGraph(graph_buffer)


def sigint_handler(num,frame):
# Clean up
    graph.DeallocateGraph()
    device.CloseDevice()
    print('Bye, after deallocategraph') 

def classify(num,frame):
    with open('/home/upsquared/py/ocr_class/pic.txt') as f:
        pic_name=f.read()
    pic = cv2.imread(pic_name)
    pic = cv2.resize(pic, (width, height), pic, interpolation=cv2.INTER_LINEAR)
    input_tensor = pic.astype(np.float16)
    print('x:',input_tensor.shape)
    
    t2=time.time()
    # Load the image to the device and trigger an inference
    graph.LoadTensor(input_tensor, 'user object')

    # Get the results from the device
    output, userobj = graph.GetResult()
    print('inference time:',time.time()-t2)
    # Do something with the results...
    print(output.shape)
    print(output)
    ki=np.argmax(output)
    kind=kinds[ki]
    print(kind)
    with open('/home/upsquared/py/ocr_class/kind.txt', 'wt') as f:
        f.write(kind)

with open('/home/upsquared/py/ocr_class/pid.txt', 'wt') as f:
    pid=os.getpid()
    print('classifyd pid:',pid)
    f.write(str(pid))
signal.signal(signal.SIGUSR1, classify)
signal.signal(signal.SIGINT, sigint_handler)
while True:
    time.sleep(20000)
