import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#--------------------
#remote connect part
#--------------------
#s.connect(('162.105.91.29',9999))

#----------------
#local test part
#----------------
s.connect(('127.0.0.1',9999))
print ((s.recv(1024)).decode('utf-8'))

#---------------
# transmit data
#---------------
s.send(('upload\r\ntest.tar.gz').encode('utf-8'))
print (s.recv(1024).decode('utf-8'))

#-----------
# test part
#-----------
for data in [b'Michael', b'Tracy', b'Sarah']:
    s.send(data)
    print (s.recv(1024).decode('utf-8'))
s.send(b'exit')
s.close()
