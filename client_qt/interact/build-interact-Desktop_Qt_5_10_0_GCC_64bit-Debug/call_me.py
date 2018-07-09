import os
import shutil

def ocr_class(pic_name,output_path, ocr_lang='chi_sim'):
    r=os.popen('python3 /home/upsquared/py/ocr_class/ocr_class.py '+ pic_name +' '+ output_path+' '+ocr_lang).read()
    print('ocr class:')
    print(r)


def face_detecting(pic_name):
    r=os.popen('python3 /home/upsquared/py/face_detect/face_detecting.py '+pic_name).read()
    if 'face_detecting_returns_True' in r:
        return True
    else:
        return False
    print(r)

if __name__=='__main__':
    output_path="/home/upsquared/py/ocr_class/data/results/"
    if os.path.exists(output_path):
        shutil.rmtree(output_path)
        os.makedirs("/home/upsquared/py/ocr_class/data/results/")
        pic_name = '/home/upsquared/Pictures/pcampus.jpg'
        ocr_class(pic_name,output_path)
        face_detecting(pic_name)
