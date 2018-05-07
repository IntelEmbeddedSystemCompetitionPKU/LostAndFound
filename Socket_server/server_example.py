import socket
import threading
import time


###########################
# Init
# server ip: 162.105.91.29
# server port: 9999
###########################

#---------------------
# remote connect part
#---------------------
#s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # generate socket description
#s.bind(('162.105.91.29',9999))  # start server in port 9999 of ip 162.105.91.29
#s.listen(5)  # listen
#print ('waiting for connection...')

#-----------------
# local test part
#-----------------
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # generate socket description
s.bind(('127.0.0.1',9999))  # start server in port 9999 of localhost
s.listen(5)  # listen
print ('waiting for connection...')




#############
# handle cmd
#############

#----------------------------------------
# upload: client uploads files to server
#----------------------------------------
def upload():
    print ('upload')

def remove():
    pass
def keywordsearch():
    pass
def detailsearch():
    pass
def identify():
    pass
def error():
    print ('error')




########################################
# distribute cmd to different functions
########################################
def cmd_distribute(cmd):
    if cmd == "upload":
        upload()
    elif cmd == "remove":
        remove()
    elif cmd == "keywordsearch":
        keywordsearch()
    elif cmd == "detailsearch":
        detailsearch()
    elif cmd == "identify":
        identify()
    else:
        error()

#-----------------
# cannot work out
#-----------------
#    distribute = {
#        'upload': upload(),
#        'remove': remove(),
#        'keywordsearch': keywordsearch(),
#        'detailsearch': detailsearch(),
#        'identify': identify(),
#    }
#    return distribute.get(cmd, error())




#########################
# response to the client
#########################
def tcplink (sock, addr):
    # show the ip of client
    # response to the client user
    print ('Accept new connection from %s:%s...' % addr)
    sock.send(('Welcome!').encode('utf-8'))

    # receive the command type of request and the main body of data
    # split them into cmd and data
    # distribute to different functions according to cmd
    cmd, data = ((sock.recv(1024)).decode('utf-8')).split('\r\n', 1)
    print ('cmd %s received!' % cmd)
    sock.send(('cmd received!' % cmd.encode('utf-8')).encode('utf-8'))
    cmd_distribute(cmd)

    #-----------
    # test part
    #-----------
    while True:
        data = sock.recv(1024)
        time.sleep(1)  # question: why sleep(1) can cut off the received data? or it works because that the client is waiting for response?
        if not data or data.decode('utf-8') == 'exit':
            break
        sock.send(('Hello, %s!' % data.decode('utf-8')).encode('utf-8'))
    sock.close()
    print ('Connection from %s:%s closed.' % addr)




############################################
# every connect will get an isolated thread
############################################
while True:
    sock, addr = s.accept()  # accept the request of client
    t = threading.Thread(target=tcplink, args=(sock,addr))  # new a thread to handle the request
    t.start()  # start the thread
