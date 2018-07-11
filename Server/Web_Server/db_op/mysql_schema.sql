user(name tinytext primary key,passwd tinytext,usruuid char(32))

lost(uuid char(32) not null primary key, lost_date date, description tinytext, ocr tinytext, usruuid char(32))

user_qrcode(usruuid char(32), qrcode char(256))

---create and initialize the database---
create database LostFound character set utf8mb4 collate utf8mb4_unicode_ci;
--alter database LostFound character set utf8mb4 collate utf8mb4_unicode_ci;
use LostFound;
create table User(
    username varchar(16),
    password varchar(32),
    useruuid varchar(32),
    constraint PK_User primary key(username)
);

create table Lost(
    objuuid varchar(32),
    lostdate date,
    description varchar(256),
    ocr varchar(256),
    findername varchar(32) default '',
    ownername varchar(32) default '',
    apply varchar(32) default '0',
    constraint PK_Lost primary key(objuuid)
);
create index clst_idx_lostdate on Lost(lostdate);

create table Anti_qrcode(
    username varchar(16),
    qrcode varchar(256),
    constraint PK_User_qrcode primary key(username,qrcode)
);

create table Messages(
    username varchar(16),
    targetname varchar(16),
    message varchar(512),
    time bigint,
    replied TINYINT
);
    --constraint FK_User_qrcode_useruuid foreign key(useruuid) references User(useruuid)

---create user and login
CREATE USER 'LostFoundDba'@'localhost' IDENTIFIED BY '123';
--drop user 'lost_found_dba'@'localhost';
grant all on LostFound.* to LostFoundDba@localhost;

mysql -uLostFoundDba -p---123
