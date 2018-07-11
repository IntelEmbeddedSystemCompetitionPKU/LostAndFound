import cv2
import numpy as np
import sys
S = 480
rx = 300
ry = 240

def face_detect(imname):
    faceCascade = cv2.CascadeClassifier('/home/upsquared/py/face_detect/model/haarcascade_frontalface_default.xml')
    faceNeighborsMax = 10
    neighborStep = 1
    frame = cv2.imread(imname)
    if frame is None:
        print('not exists!')
        return
    cv2.circle(frame, (rx, ry), S//2, (0, 255, 0), thickness=2, lineType=cv2.LINE_AA)
    s=frame.shape
    frame = frame[s[0]//6:s[0]*5//6, s[1]//6:s[1]*5//6, :]
    frame_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    print(frame_gray)
    '''
    for i in range(S):
        for j in range(S):
            if (i-S/2)**2+(j-S/2)**2 > (S/2)**2:
                frame_gray[j][i] = 0
       '''
        #cv2.imshow('frame_gray', frame_gray)
    faces = faceCascade.detectMultiScale(frame_gray, 1.1, 3, minSize=(400,400))
    if len(faces)>0:
        print('face_detecting_returns_True')
    else:
        print('face_detecting_returns_False')
'''     frameClone = np.copy(frame)
        if len(faces) == 0:
            cv2.putText(frameClone, 'No face detected!', (10, 40),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 4)
        else:
            cv2.putText(frameClone, 'Thank u', (10, 40),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 4)
        for (x, y, w, h) in faces:
            cv2.rectangle(frameClone, (x, y), (x+w, y+h), (255, 0, 0), 2)
        cv2.imshow('Face Detection Demo', frameClone)
        if cv2.waitKey(500) & 0xFF == 27:
            cv2.destroyAllWindows()
			exit(0)
'''
if __name__=='__main__':
    face_detect(sys.argv[1])

