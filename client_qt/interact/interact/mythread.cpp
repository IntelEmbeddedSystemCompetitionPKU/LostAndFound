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
MyThread::MyThread(QObject *parent):QThread(parent) {}
MyThread::~MyThread() {}
void MyThread::run() {
    MyPython myPython;
    myPython.init();
    QString result;
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
    }
    else if(command.contains("get")) {
        qDebug() << "before get";
        myPython.getItem(uuid);
    }
    else if(command.contains("refresh")) {
        qDebug() << "before refresh";
        myPython.refreshDesc(uuid, args, desc);
    }
    else if(command.contains("savemark")) {
        qDebug() << "before save";
        myPython.saveItem(uuid);
        qDebug() << "before uploadmark";
        myPython.uploadMark(uuid, desc);
    }
    else if(command.contains("picker")) {
        qDebug() << "before picker";
        myPython.uploadPicker(uuid, desc);
    }
    finish(result);
    myPython.finish();
    exit(0);
}
void MyThread::setCommand(QString _command) {
    command = _command;
}
void MyThread::setArgs(QString _args) {
    args = _args;
}
void MyThread::startProcess() {
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
    QJsonParseError json_error;
    QJsonDocument docu = QJsonDocument::fromJson(input.toUtf8(), &json_error);
    QString result = QString("");
    if(json_error.error == QJsonParseError::NoError) {
        if(docu.isObject()) {
            QJsonObject jsonObject = docu.object();
            if(jsonObject.contains("key")) {
                QJsonValue Jvalue = jsonObject.take("key");
                result = Jvalue.toString();
                Jvalue = jsonObject.take("value");
                desc = Jvalue.toString();
                if(result == "fetch") {
                    uuid = Jvalue.toString();
                }
            }
        }
    }
    return result;
}
