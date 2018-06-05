#include "datamanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QZXing.h>
#include <QUuid>

QUuid datamanager::nowUUID = NULL;
QString datamanager::description = NULL;
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QZXing::registerQMLTypes();    
    QGuiApplication app(argc, argv);
    qmlRegisterType<datamanager>("user.DataManager",1,0,"DataManager");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
