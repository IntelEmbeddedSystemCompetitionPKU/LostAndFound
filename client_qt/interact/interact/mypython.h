#ifndef MYPYTHON_H
#define MYPYTHON_H
#include <Python.h>
#include <QString>
class MyPython {
public:
    MyPython();
    ~MyPython();
    bool init(); //done
    bool isExist(QString uuid); // directly python
    bool isFacePhoto(QString uuid);
    void imageProcess(QString uuid, QString number);
    QString loadResult(QString uuid, QString number);
    void saveItem(QString uuid);
    void getItem(QString uuid);
    void refreshDesc(QString uuid, QString number, QString desc);
    void finish();
    void uploadMark(QString uuid, QString desc);
    void uploadPicker(QString uuid, QString desc);
private:
    PyObject* pModule;
};
#endif // MYPYTHON_H
