import pymysql


def cnnct():
    db = pymysql.connect(
        "localhost", user='root', password='', database="lost_found")
    c = db.cursor()
    return db, c
