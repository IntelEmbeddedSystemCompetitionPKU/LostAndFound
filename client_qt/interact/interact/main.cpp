#include "mythread.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QZXing.h>
#include <QUuid>

QString MyThread::uuid = "uuid";
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QZXing::registerQMLTypes();    
    QGuiApplication app(argc, argv);
    qmlRegisterType<MyThread>("user.MyThread",1,0,"MyThread");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
