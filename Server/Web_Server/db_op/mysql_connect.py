import pymysql
import hashlib

host = 'localhost'
# host = '10.128.171.97'
dba, password='LostFoundDba','123'
# dba, password='root','ykx970910'

def cnnct():
    db = pymysql.connect(
        host, user=dba, password=password, database="LostFound",  autocommit=True)
    c = db.cursor()
    return db, c

def is_password_right(username,passwd):
    db, c =  cnnct()
    password=get_md5(passwd + username + 'Author:fcg,yql,ykx')
    # try:
    sql = 'select * from User where username="'+username+'" and password="'+passwd+'";'
    print(sql)
    r=c.execute(sql)
    if r==1:
        db.close()
        return True
    else:
        db.close()
        return False
    # except:
    #     db.close()
    #     return False


def query_mysql(contents, table, where='true'):
    db,c =cnnct()
    c.execute("SELECT " + contents + " FROM " + table + " WHERE "+where+";")
    results = c.fetchall() # type(results) == tuple
    c.close()
    db.close()
    return results


if __name__=='__main__':
    db,c = cnnct()
    r=c.execute('select * from User where username="richsoap" and password="testinggg";')
    print('return',r)
    # c.execute('insert into User values("lily","pswd","lilyuiid");')
    db.close()