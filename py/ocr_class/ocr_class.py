from __future__ import print_function
import numpy as np
import os
import sys
import cv2
import time
import pandas as pd
import pytesseract as ts
import shutil
import os
import signal

def draw_boxes(img,df,pic_name,output_path,rst_name):
    color=(125,125,125)
    ocr_words={}
    base_name = pic_name.split('/')[-1]
    rst_img=os.path.join(output_path, base_name)
    print(rst_img)
    print(rst_name)
    print('rst_img:',rst_img)
    with open(rst_name,'ta') as f:
        i=0
        for _, e in df.iterrows():
            left, width, top, height, text = e['left'], e['width'], e['top'], e['height'], e['text']
            p00=(left, top)
            p01=(left, top+height)
            p10=(left+width, top)
            p11=(left+width, top+height)
            cv2.line(img, p00, p01, color, 2)
            cv2.line(img, p01, p11, color, 2)
            cv2.line(img, p11, p10, color, 2)
            cv2.line(img, p10, p00, color, 2)
            #img[min_y:max_y,min_x:max_x]=0
            cv2.putText(img, '['+str(i)+']', p10, cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)  
            content='block'+str(i)+' '+text.strip().replace(' ','')
            f.write(content+'\n')
            print(content)
            i+=1
    cv2.imwrite(rst_img,img)
    with open(rst_name, 'rt') as f:
        print('read after write')
        print(f.read())

def ocr_(pic_name,output_path, ocr_lang, rst_name):
    im = cv2.imread(pic_name)
    if im is None:
        print('Image file not exists!')
        return
    sh='/home/upsquared/py/ocr_class/textcleaner '+pic_name+' /home/upsquared/py/ocr_class/textcleanertmp.jpg'
    #print(sh)
    t1=time.time()
    os.system(sh)
    print('preprocess ',time.time()-t1)
    im_clean = cv2.imread('/home/upsquared/py/ocr_class/textcleanertmp.jpg')
    #im_clean = im
    #if im.shape[0]>2000:
    #iim=cv2.resize(im,None, fx=1/4,fy=1/4, interpolation=cv2.INTER_LINEAR)
    print('image size:',im.shape)
    #print(ts.get_tesseract_version())
    #stri = ts.image_to_string(im,lang=ocr_lang)
    #boxes = ts.image_to_boxes(im,lang=ocr_lang)
    t1=time.time()
    data = ts.image_to_data(im_clean, lang=ocr_lang,output_type=ts.Output.DICT)
    #osd = ts.image_to_osd(im, lang='eng')
    print('tesseract:',time.time()-t1)
    df=pd.DataFrame(data)
    df=df[['left','width','top','height','text','conf']]
    df=df[df['conf']>60]
    df=df[df['text'].str.replace(' ','').replace('\t','').replace('\n','').str.len()>0]
    df=df.sort_values(['top','left'])
    print(df)
    print('before draw_boxes')
    draw_boxes(im, df, pic_name,output_path,rst_name)
    print('after draw_boxes')

def cls(pic_name, rst_name, args):
    with open('/home/upsquared/py/ocr_class/pic.txt', 'wt') as f:
        print('cls '+pic_name)
        f.write(pic_name)
    with open('/home/upsquared/py/ocr_class/pid.txt') as f:
        pid=f.read()
        print('pid in pid.txt: ',pid)
    os.kill(int(pid), signal.SIGUSR1)
    print('wait classifyd')
    ocr_(args[1],args[2],args[3],rst_name)
    #time.sleep(1)
    print('get result')
    with open('/home/upsquared/py/ocr_class/kind.txt') as f:
        kind = f.read()
        print('cls result: ',kind)
    kind='card'
    with open(rst_name, 'rt') as f:
        tmp=f.read()
    with open(rst_name, 'wt') as f:
        f.write('kind '+kind+'\n'+tmp)
    return kind

if __name__ == '__main__':
    args=sys.argv
    print(args)
    base_name = args[1].split('/')[-1]
    rst_name = os.path.join(args[2], base_name[:-4]) + '.txt'
    if cls(args[1],rst_name,args)=='card' or True:
        print('card needs ocr')
        #ocr_(args[1],args[2],args[3],rst_name)
    #exit(0)
