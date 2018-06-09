#include "datamanager.h"
#include <QUuid>
#include <QDir>
#include <QObject>
#include <QDebug>
#include <QFile>
datamanager::datamanager(QObject *parent):QObject(parent) {}
datamanager::~datamanager() {}
void datamanager::setUUID() {
    nowUUID = QUuid::createUuid();
    QString fullPath = getDir();
    QDir dir(fullPath);
    qDebug() << "dir make" << dir.mkpath(fullPath);
    qDebug() << "dir is" << fullPath;
    qDebug() << "HD make" << dir.mkpath(fullPath + "HD/");
    qDebug() << "ocr make" << dir.mkpath(fullPath + "ocr/");
}
QString datamanager::getDir() {
    return "/home/upsquared/workspace/data/" + getUUIDString() + "/";
}
void datamanager::processImage() {
    QFile file(getDir() + "desc.txt");
    file.open(QIODevice::WriteOnly);
    std::string str = description.toStdString();
    file.write(str.c_str(), description.length());
    file.close();
    startScripts();
}
QString datamanager::getUUIDString() {
    QString uuid = nowUUID.toString();
    uuid.remove(0,1);
    uuid.remove(uuid.length() - 1, 1);
    uuid.remove(8,1);
    uuid.remove(12,1);
    uuid.remove(16,1);
    uuid.remove(20,1);
    return uuid;
}
void datamanager::addDescription(QString desc) {
    description = desc;
}

void datamanager::startScripts(){
    process = new myProcess("python3");
    process->addParam("/home/upsquared/workspace/LostAndFound/client_qt/upload/upload.py");
    process->addParam("-mode=new");
    process->addParam("-srcdir=" + getDir());
    process->start();
}
