import cv2
import numpy as np

S = 480
rx = 300
ry = 240

def face_detect(imname):
    faceCascade = cv2.CascadeClassifier('models/haarcascade_frontalface_default.xml')
    faceNeighborsMax = 10
    neighborStep = 1
    frame = cv2.imread(imname)
    cv2.circle(frame, (rx, ry), S//2, (0, 255, 0), thickness=2, lineType=cv2.LINE_AA)
    frame_resize = frame[:, 80:-80, :]
    frame_gray = cv2.cvtColor(frame_resize, cv2.COLOR_BGR2GRAY)
    for i in range(S):
        for j in range(S):
            if (i-S/2)**2+(j-S/2)**2 > (S/2)**2:
                frame_gray[j][i] = 0
        cv2.imshow('frame_gray', frame_gray)
        faces = faceCascade.detectMultiScale(
            frame_gray, 1.1, 3, minSize=(300, 300))
        return len(faces)>0
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
