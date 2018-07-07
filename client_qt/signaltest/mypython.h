#ifndef MYPYTHON_H
#define MYPYTHON_H
#include <Python.h>
#include <QString>
class MyPython {
public:
    MyPython();
    ~MyPython();
    bool init();
    bool isExist(QString uuid);
    bool isFacePhoto(QString path);
    void imageProcess(QString path);
    QString loadResult(QString path);
    bool saveItem(QString uuid);
    bool getItem(QString uuid);
    void uploadInformation(QString uuid);
    QString test(int input);
    void finish();

};
#endif // MYPYTHON_H
