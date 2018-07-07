#include "mythread.h"
#include "mypython.h"
#include <QObject>
#include <QDebug>
MyThread::MyThread(QObject *parent) : QThread(parent),number(0) {}
void MyThread::startTest(int input) {
    number = input;
    qDebug() << "before start";
    this->start();
}
void MyThread::run() {
    MyPython scripts;
    qDebug() << "in run";
    if(scripts.init()) {
        qDebug() << "before test";
        QString result = scripts.test(number);
        qDebug() << "after test";
        finished(result);
        qDebug() << "after signaling";
        scripts.finish();
    }
    exit(0);
}
