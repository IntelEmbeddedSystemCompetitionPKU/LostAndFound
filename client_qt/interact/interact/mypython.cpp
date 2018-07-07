#include "mypython.h"
#include <QDebug>
#include <stdio.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
MyPython::MyPython() { }
MyPython::~MyPython() {}
bool MyPython::init() {
    Py_Initialize();
    if (!Py_IsInitialized())
        return false;
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./scipts/')");
    pModule = PyImport_ImportModule("maininterface");
    if(!pModule) {
        return false;
    }
    return true;
}
bool MyPython::isExist(QString uuid) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "isexist");
    PyObject *pArg = Py_BuildValue("(s)", uuid.toStdString().c_str());
    PyObject *result = PyEval_CallObject(pFunc, pArg);
    int res;
    PyArg_ParseTuple(result, "i", &res);
    qDebug()<< "after call";
    if(res == 0)
        return true;
    else
        return false;
}
bool MyPython::isFacePhoto(QString uuid){
    PyObject *pFunc = PyObject_GetAttrString(pModule, "isface");
    PyObject *pArg = Py_BuildValue("(s)", uuid.toStdString().c_str());
    PyObject *result = PyEval_CallObject(pFunc, pArg);
    int res;
    PyArg_ParseTuple(result, "i", &res);
    qDebug()<< "after call";
    if(res == 0)
        return true;
    else
        return false;
}
void MyPython::imageProcess(QString uuid, QString number) {
    qDebug() << "before pFunc";
    PyObject *pFunc = PyObject_GetAttrString(pModule, "classify");
    qDebug() << "before pArg";
    PyObject *pArg = Py_BuildValue("(s,i)", uuid.toStdString().c_str(), number.toInt());
    PyEval_CallObject(pFunc, pArg);
}
QString MyPython::loadResult(QString uuid, QString number){
    PyObject *pFunc = PyObject_GetAttrString(pModule, "loadresult");
    PyObject *pArg = Py_BuildValue("(s,i)", uuid.toStdString().c_str(), number.toInt());
    PyObject *result = PyEval_CallObject(pFunc, pArg);
    char* res;
    PyArg_ParseTuple(result, "s", &res);
    return QString(res);
}
void MyPython::saveItem(QString uuid) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "save");
    PyObject *pArg = Py_BuildValue("(s)", uuid.toStdString().c_str());
    PyEval_CallObject(pFunc, pArg);
}
void MyPython::getItem(QString uuid) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "load");
    PyObject *pArg = Py_BuildValue("(s)", uuid.toStdString().c_str());
    PyEval_CallObject(pFunc, pArg);
}
void MyPython::finish() {Py_Finalize();}
void MyPython::refreshDesc(QString uuid,QString num, QString desc) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "refresh");
    PyObject *pArg = Py_BuildValue("(s,i,s)", uuid.toStdString().c_str(),num.toInt(), desc.toStdString().c_str());
    PyEval_CallObject(pFunc, pArg);
}

void MyPython::uploadMark(QString uuid, QString desc) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "uploadMark");
    PyObject *pArg = Py_BuildValue("(s,s)", uuid.toStdString().c_str(), desc.toStdString().c_str());
    PyEval_CallObject(pFunc, pArg);
}

void MyPython::uploadPicker(QString uuid, QString desc) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "uploadPicker");
    PyObject *pArg = Py_BuildValue("(s,s)", uuid.toStdString().c_str(), desc.toStdString().c_str());
    PyEval_CallObject(pFunc, pArg);
}