import pymysql
import hashlib
import base64
from Crypto.Cipher import AES
from Web_Server.settings import aes_key
host = 'localhost'
# host = '10.128.171.97'
dba, password='LostFoundDba','123'
# dba, password='root','ykx970910'

import hashlib

def get_md5(s):
    md5=hashlib.md5(s.encode('utf-8')).hexdigest()
    return md5

def encrypt(plaintext):
    obj = AES.new(aes_key, AES.MODE_CFB, 'This is an IV456')
    pb=plaintext.encode()
    c=obj.encrypt(pb)
    b=base64.b64encode(c)
    s=b.decode()
    return s

def decrypt(cyphertext):
    obj = AES.new(aes_key, AES.MODE_CFB, 'This is an IV456')
    b=cyphertext.encode()
    c=base64.b64decode(b)
    pb=obj.decrypt(c)
    p=pb.decode()
    return p

def cnnct():
    db = pymysql.connect(
        host, user=dba, password=password, database="LostFound",  autocommit=True)
    c = db.cursor()
    return db, c

def is_password_right(username,passwd):
    db, c =  cnnct()
    passwd=get_md5(passwd)
    r=c.execute('select * from User where username=%s and password=%s', (username,passwd))
    if r==1:
        db.close()
        return True
    else:
        db.close()
        print(passwd+' is wrong passwd_md5')
        return False


def query_mysql(contents, table, where='true'):
    db,c =cnnct()
    sql = "SELECT " + contents + " FROM " + table + " WHERE "+where+";"
    print(sql)
    c.execute(sql)
    results = c.fetchall()
    c.close()
    db.close()
    return results


def query_sql(sql, params):
    db,c =cnnct()
    print(sql,params)
    c.execute(sql,params)
    results = c.fetchall()
    c.close()
    db.close()
    return results

def nofetchall_sql(sql, params):
    db,c =cnnct()
    print(sql,params)
    r=c.execute(sql,params)
    c.close()
    db.close()
    return r
    

if __name__=='__main__':
    # db,c = cnnct()
    # r=c.execute('select * from User where username="richsoap" and password="testinggg";')
    # print('return',r)
    # # c.execute('insert into User values("lily","pswd","lilyuiid");')
    # db.close()
    pass