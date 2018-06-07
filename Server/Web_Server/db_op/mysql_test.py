import pymysql


db = pymysql.connect("localhost",user='root', password='',database="lost_found")
c = db.cursor()
r=c.execute('show tables;')
r=c.fetchall()
print('show tables: ',r)
db.close()