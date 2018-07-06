#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QObject>
#include<QThread>
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject* parent = 0);
    ~MyThread();
    void run();
    Q_INVOKABLE void setCommand(QString _command);
    Q_INVOKABLE void setArgs(QString _args);
    Q_INVOKABLE void setUUID(QString _uuid);
    Q_INVOKABLE void getNewUUID();
    Q_INVOKABLE void startProcess();
    Q_INVOKABLE static QString getDir();
private:
    QString command;
    QString args;
    static QString uuid;
signals:
    void finish(QString result);

};

#endif // MYTHREAD_H
