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
FLAGS = None
kinds=['card','key','phone','wallet','other']
width = 224
height = 224

def classify(pic_name):
    t1 = time.time()
    pic = cv2.imread(pic_name)
    pic = cv2.resize(pic, (width, height), pic, interpolation=cv2.INTER_LINEAR)
    input_tensor = pic.astype(np.float16)
    print('x:',input_tensor.shape)
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
    t2=time.time()
    # Load the image to the device and trigger an inference
    graph.LoadTensor(input_tensor, 'user object')

    # Get the results from the device
    output, userobj = graph.GetResult()
    print('inference time:',time.time()-t2)
    # Do something with the results...
    #print(output.shape)
    print(output)
    ki=np.argmax(output)
    
    t2=time.time()
    # Load the image to the device and trigger an inference
    graph.LoadTensor(input_tensor, 'user object')

    # Get the results from the device
    output, userobj = graph.GetResult()
    print('inference time:',time.time()-t2)
    # Do something with the results...
    #print(output.shape)
    print(output)
    ki=np.argmax(output)

    # Clean up
    graph.DeallocateGraph()
    device.CloseDevice()
    print('total time:',time.time()-t1)
    return kinds[ki]

if __name__ == '__main__':
    kind = classify('/home/upsquared/py/ocr_class/p1.jpg')
    print(kind)
