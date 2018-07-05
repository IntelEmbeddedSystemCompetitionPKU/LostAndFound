#ifndef MYPYTHON_H
#define MYPYTHON_H
#include <Python.h>
#include <QString>
class MyPython {
public:
    MyPython();
    ~MyPython();
    bool init(); //done
    bool isExist(); // directly python
    bool isFacePhoto();
    void imageProcess(int number);
    QString loadResult(int number);
    bool saveItem();
    bool getItem();
    void uploadInformation();
    QString test(int input);
    void finish();
    void addDesc(QString desc);

};
#endif // MYPYTHON_H
