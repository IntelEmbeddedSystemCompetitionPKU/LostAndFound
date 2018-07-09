#include "mythread.h"
#include "mypython.h"
#include<QObject>
#include<QThread>
#include<QUuid>
#include<QDir>
#include<QDebug>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
MyThread::MyThread(QObject *parent):QThread(parent) {}
MyThread::~MyThread() {}
void MyThread::run() {
    qDebug() << "running";
    MyPython myPython;
    myPython.init();
    qDebug() << "after init";
    QString result = "";
    if(command.contains("classify")) {
        qDebug() << "before classify";
        myPython.imageProcess(uuid, args);
        qDebug() << "before load";
        result = myPython.loadResult(uuid, args);
    }
    else if(command.contains("face")) {
        qDebug() << "before face";
        if(myPython.isFacePhoto(uuid)) {
            result = "True";
        }
        else {
            result = "False";
        }
    }
    else if(command.contains("save")) {
        qDebug() << "before save";
        myPython.saveItem(uuid);
        if(command.contains("mark")) {
            qDebug() << "before uploadmark";
            myPython.uploadMark(uuid, desc);
        }
        result = "pop";
    }
    else if(command.contains("get")) {
        qDebug() << "before get";
        myPython.getItem(uuid);
        result = "pop";
    }
    else if(command.contains("refresh")) {
        qDebug() << "before refresh";
        myPython.refreshDesc(uuid, args, desc);
        result = "";
    }
    else if(command.contains("picker")) {
        qDebug() << "before picker";
        qDebug() << uuid << desc;
        myPython.uploadPicker(uuid, desc);
        result = "pop";
    }
    finish(result);
    qDebug() << "finish " << result;
    exit(0);
}
void MyThread::setCommand(QString _command) {
    qDebug() << "set command " + _command;
    command = _command;
}
void MyThread::setArgs(QString _args) {
    args = _args;
}
void MyThread::startProcess() {
    qDebug() << "try to start";
    this->start();
}
void MyThread::setUUID(QString _uuid) {
    uuid = _uuid;
}
void MyThread::getNewUUID() {
    QUuid tempUUID = QUuid::createUuid();
    uuid = tempUUID.toString();
    uuid.remove(0,1);
    uuid.remove(uuid.length() - 1, 1);
    uuid.remove(8,1);
    uuid.remove(12,1);
    uuid.remove(16,1);
    uuid.remove(20,1);
    QString fullPath = getDir();
    QDir dir(fullPath);
    qDebug() << "dir make" << dir.mkpath(fullPath);
    qDebug() << "dir is" << fullPath;
    qDebug() << "HD make" << dir.mkpath(fullPath + "HD/");
    qDebug() << "OCR make" << dir.mkpath(fullPath + "OCR/");
    qDebug() << "fetch make" << dir.mkpath(fullPath + "fetch/");
    qDebug() << "mask make" << dir.mkpath(fullPath + "mask/");
}

QString MyThread::getDir() {
    //return "/home/richsoap/workspace/data/" + uuid + "/";
    return "/home/upsquared/workspace/data/" + uuid + "/";
}

void MyThread::addDesc(QString desct) {
    desc = desct;
}

QString MyThread::processQR(QString input) {
    QString result = QString("");
    if(input.startsWith("user")) {
        result = "user";
        desc = input.mid(4);
    }
    else if(input.startsWith("mark")) {
        result = "mark";
        desc = input.mid(4);
    }
    else if(input.startsWith("fetc")) {
        result = "fetch";
        uuid = input.mid(4);
    }
    return result;
}
