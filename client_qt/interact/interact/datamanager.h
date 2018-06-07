#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QString>
#include <QUuid>
#include <QObject>
class datamanager : public QObject {
    Q_OBJECT

private:
    static QUuid nowUUID;
    static QString description;


public:
    datamanager(QObject *parent = 0);
    ~datamanager();
    Q_INVOKABLE static void setUUID();
    Q_INVOKABLE static QString getDir();
    Q_INVOKABLE static void processImage();
    Q_INVOKABLE static void addDescription(QString desc);
    static QString getUUIDString();
};

#endif // DATAMANAGER_H
