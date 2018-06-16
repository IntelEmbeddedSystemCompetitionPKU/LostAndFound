#include "datamanager.h"
#include <QUuid>
#include <QDir>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
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
    qDebug() << "fetch make" << dir.mkpath(fullPath + "fetch/");

}
QString datamanager::getDir() {
    //return "/home/richsoap/workspace/data/" + getUUIDString() + "/";
    return "/home/upsquared/workspace/data/" + getUUIDString() + "/";
}
void datamanager::processImage() {
    QFile file(getDir() + "desc.txt");
    file.open(QIODevice::WriteOnly);
    std::string str = description.toStdString();
    file.write(str.c_str(), description.length());
    file.close();
    process = new myProcess("python3");
    process->addParam("/home/upsquared/workspace/LostAndFound/client_qt/upload/upload.py");
    process->addParam("-mode=new");
    process->addParam("-srcdir=" + getDir());
    process->start();
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

bool datamanager::isExist(QString name) {
    return true;
    QString val;
    QFile file;
    file.setFileName("/home/upsquared/workspace/LostAndFound/client_qt/upload/log.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject obj = document.object();
    return obj.contains(name);
}

void datamanager::popOut(QString name) {
    process = new myProcess("python3");
    process->addParam("/home/upsquared/workspace/LostAndFound/client_qt/upload/upload.py");
    process->addParam("-mode=old");
    qDebug() << "Start get item";
    process->addParam("-srcdir=" + getDir());
    process->start();
}
