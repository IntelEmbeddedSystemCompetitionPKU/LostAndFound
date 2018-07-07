from __future__ import print_function
import numpy as np
import os
import sys
import cv2
import time
import pandas as pd
import pytesseract as ts
import shutil
import classify as cl

def draw_boxes(img,df,pic_name,output_path,kind):
    base_name = pic_name.split('/')[-1]
    color=(125,125,125)
    ocr_words={}
    # with open('data/results/' + 'res_{}.txt'.format(base_name.split('.')[0]), 'w') as f:
    
    with open(os.path.join(output_path, "words_"+base_name),'ta') as f:
        f.write('kind '+kind+'\n')
        for i,e in df.iterrows():
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
            f.write(str(i)+' '+text.strip().replace(' ','')+'\n')
    cv2.imwrite(os.path.join(output_path, "mask_"+base_name), img)

def ocr_class(pic_name,output_path, ocr_lang='chi_sim'):
    kind=cl.classify(pic_name)
    print(kind)
    im = cv2.imread(pic_name)
    if im is None:
        print('Image file not exists!')
        exit(-1)
    if im.shape[0]>2000:
        im=cv2.resize(im,None, fx=1/4,fy=1/4, interpolation=cv2.INTER_LINEAR)
    print('image size:',im.shape)
    #print(ts.get_tesseract_version())
    stri = ts.image_to_string(im,lang=ocr_lang)
    boxes = ts.image_to_boxes(im,lang=ocr_lang)
    data = ts.image_to_data(im, lang=ocr_lang,output_type=ts.Output.DICT)
    #osd = ts.image_to_osd(im, lang='eng')
    df=pd.DataFrame(data)
    df=df[['left','width','top','height','text','conf']]
    df=df[df['conf']>60]
    df=df[df['text'].str.replace(' ','').replace('\t','').str.len()>0]
    df=df.sort_values(['top','left'])
    print(df)
    draw_boxes(im, df, pic_name,output_path,kind)

if __name__ == '__main__':
    output_path="data/results/"
    if os.path.exists(output_path):
        shutil.rmtree(output_path)
    os.makedirs("data/results/")
    pic_name = '/home/upsquared/Pictures/p9.jpg'
    ocr_class(pic_name,output_path)
