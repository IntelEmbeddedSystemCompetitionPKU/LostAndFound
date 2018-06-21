user(name tinytext primary key,passwd tinytext,usruuid char(32))

lost(uuid char(32) not null primary key, lost_date date, description tinytext, ocr tinytext, usruuid char(32))

user_qrcode(usruuid char(32), qrcode char(256))

---initialize the database---
use lost_found;
create table User(
    username varchar(16),
    password varchar(16),
    useruuid char(32),
    constraint PK_User primary key(username)
);

create table Lost(
    objuuid char(32),
    lostdate date,
    description varchar(256),
    ocr varchar(256),
    useruuid char(32) default '0',
    constraint PK_Lost primary key(objuuid)
);
create index clst_idx_lostdate on Lost(lostdate);

create table User_qrcode(
    useruuid char(32),
    qrcode varchar(256),
    constraint PK_User_qrcode primary key(useruuid,qrcode)
);
    --constraint FK_User_qrcode_useruuid foreign key(useruuid) references User(useruuid)
