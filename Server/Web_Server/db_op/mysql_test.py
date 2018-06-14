import pymysql
from sqlconnect import *

db = pymysql.connect("localhost",user='root', password='',database="lost_found")
c = db.cursor()
r=c.execute('show tables;')
r=c.fetchall()
print('show tables: ',r)
db.close()

db,c = cnnct()
try:
    r=c.execute("insert into user values('fcg2','haha2','21234567890123456789012345678901');")
# print('return',r)
except:
    print('error insert fcg2')
try:
    r = c.execute('select * from user where username="fcg2" and passwd="haha12";')
    print(r)
except:
    print('error select')
db.close()
