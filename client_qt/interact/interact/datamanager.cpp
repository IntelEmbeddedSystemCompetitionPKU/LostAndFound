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
    QString fullPath = "/home/richsoap/Workspaces/QtDirTest/";
    fullPath += getUUIDString();
    fullPath += "/";
    QDir dir(fullPath);
    qDebug() << "dir make" << dir.mkdir(fullPath);
    qDebug() << "dir is" << fullPath;
}
QString datamanager::getDir() {
    return "/home/richsoap/Worksapces/QtDirTest/" + getUUIDString() + "/";
}
void datamanager::processImage() {
    QFile file("/home/richsoap/Workspaces/QtDirTest/" + getUUIDString() + "/desc.txt");
    file.open(QIODevice::WriteOnly);
    std::string str = description.toStdString();
    file.write(str.c_str(), description.length());
    file.close();
}
QString datamanager::getUUIDString() {
    QString uuid = nowUUID.toString();
    uuid.remove(0,1);
    uuid.remove(uuid.length() - 1, 1);
    return uuid;
}
void datamanager::addDescription(QString desc) {
    description = desc;
}
