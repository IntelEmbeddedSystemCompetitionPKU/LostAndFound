#include "mypython.h"
#include <QDebug>
#include <stdio.h>
MyPython::MyPython() { }
MyPython::~MyPython() {}
bool MyPython::init() {
    Py_Initialize();
    if (!Py_IsInitialized())
        return false;
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    return true;
}
bool MyPython::isExist(QString uuid) {return true;}
bool MyPython::isFacePhoto(QString path){return true;}
void MyPython::imageProcess(QString path) {}
QString MyPython::loadResult(QString path){return "test";}
bool MyPython::saveItem(QString uuid) {return true;}
bool MyPython::getItem(QString uuid) {return true;}
void MyPython::uploadInformation(QString uuid) {}
void MyPython::finish() {Py_Finalize();}
QString MyPython::test(int input) {
        PyObject *pModule = PyImport_ImportModule("TestModule");
        qDebug() << "Module";
        if(!pModule) {
            return "Wrong filename";
        }
        PyObject *pFunc = PyObject_GetAttrString(pModule, "int2str");
        qDebug() << "Func";
        PyObject *pArg = Py_BuildValue("(i)", input);
        qDebug() << "Parg";
        PyObject *result = PyEval_CallObject(pFunc, pArg);
        qDebug() << "Call";
        char* buffer;
        int res;
        PyArg_ParseTuple(result, "s", &buffer);
        qDebug()<< "after call";
        printf("%s",buffer);
        return QString(buffer);
}
