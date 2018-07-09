import os
import shutil
import time
def ocr_class(pic_name,output_path, ocr_lang='chi_sim'):
    r=os.popen('python3 /home/upsquared/py/ocr_class/ocr_class.py '+ pic_name +' '+ output_path+' '+ocr_lang).read()
    print('ocr class:')
    print(r)
    print('over')

def face_detecting(pic_name):
    r=os.popen('python3 /home/upsquared/py/face_detect/face_detecting.py '+pic_name).read()
    print(r)
    if 'face_detecting_returns_True' in r:
        return True
    else:
        return False
    print(r)
    
def open_door(location):
    r = os.popen('python3 /home/upsquared/py/gpio.py ' + str(location)).read()
    print(r)

if __name__=='__main__':
    output_path="/home/upsquared/py/ocr_class/data/results/"
    if os.path.exists(output_path):
        #shutil.rmtree(output_path)
        #os.makedirs("/home/upsquared/py/ocr_class/data/results/")
        pic_name = '/home/upsquared/Pictures/pcampus.jpg'
        print(pic_name)
        t1=time.time()
        ocr_class(pic_name,output_path)
        t2=time.time()
        print('ocr and class spent ',t2-t1) 
        t3=time.time()
        face_detecting(pic_name)
        t4=time.time()
        #print('face_detecting spent ', t4-t3)
    else:
        print(output_path+'not exists')
