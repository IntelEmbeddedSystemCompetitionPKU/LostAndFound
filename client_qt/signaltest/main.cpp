#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Python.h>
#include <iostream>
#include "mythread.h"
using namespace std;
int main(int argc, char *argv[])
{
   QGuiApplication app(argc, argv);
   qmlRegisterType<MyThread>("user.MyThread",1,0,"MyThread");
   QQmlApplicationEngine engine;
   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
   if (engine.rootObjects().isEmpty())
       return -1;

   return app.exec();
}
