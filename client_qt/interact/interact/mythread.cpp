#include "mythread.h"

#include<QObject>
#include<QThread>
MyThread::MyThread(QObject *parent):QThread(parent) {}
MyThread::~MyThread() {}
void MyThread::run() {

    if(command == )
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
    qDebug() << "ocr make" << dir.mkpath(fullPath + "ocr/");
    qDebug() << "fetch make" << dir.mkpath(fullPath + "fetch/");
}

QString MyThread::getDir() {
    //return "/home/richsoap/workspace/data/" + getUUIDString() + "/";
    return "/home/upsquared/workspace/data/" + uuid + "/";
}
