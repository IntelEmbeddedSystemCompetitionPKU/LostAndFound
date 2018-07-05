#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject *parent = nullptr);
    Q_INVOKABLE void startTest(int input);
    void run();
private:
    int number;
signals:
    void finished(QString result);
};

#endif // MYTHREAD_H
