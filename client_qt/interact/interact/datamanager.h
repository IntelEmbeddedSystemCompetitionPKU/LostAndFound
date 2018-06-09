#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QString>
#include <QUuid>
#include <QObject>
#include <QProcess>
class myProcess {
    QProcess inprocess;
    QString program;
    QStringList param;
public: myProcess(QString filename) {
        program = filename;
    }
public: void addParam(QString paramitem) {
        param.append(paramitem);
    }
public: void start() {
        inprocess.start(program, param);
        inprocess.waitForFinished(300000);
    }
};

class datamanager : public QObject {
    Q_OBJECT

private:
    static QUuid nowUUID;
    static QString description;
    static myProcess* process;


public:
    datamanager(QObject *parent = 0);
    ~datamanager();
    Q_INVOKABLE static void setUUID();
    Q_INVOKABLE static QString getDir();
    Q_INVOKABLE static void processImage();
    Q_INVOKABLE static void addDescription(QString desc);
    Q_INVOKABLE static void startScripts();
    static QString getUUIDString();
    static void deleteLater();
};

#endif // DATAMANAGER_H
