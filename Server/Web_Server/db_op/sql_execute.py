import pymysql


def sql_execute(t,s):
    db = pymysql.connect(
            "localhost", user='root', password='', database="lost_found")
    c = self.db.cursor()


if __name__=='__main__':
    c=Cnnct()
    c.db.close()