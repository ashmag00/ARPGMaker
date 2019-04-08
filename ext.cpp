#include <Python.h>
#include <iostream>
#include <string>

#include "engine/main.cpp"

using namespace std;

void printHello() {
    cout << "Hello World!" << endl;
}

static PyObject *ARPGMaker_hello(PyObject *self, PyObject *args) {
    printHello();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_system(PyObject *self, PyObject *args) {
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

static PyObject *ARPGMaker_init(PyObject *self, PyObject *args) {
    int resX;
    int resY;
    char *title;

    if (!PyArg_ParseTuple(args, "iis", &resX, &resY, &title))
        return NULL;
        
    init(resX, resY, title);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_display(PyObject *self, PyObject *args) {
    display();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_close(PyObject *self, PyObject *args) {
    close();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_systemEventHandler(PyObject *self, PyObject *args) {
    systemEventHandler();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_isKeyPressed(PyObject *self, PyObject *args) {
    char *key;
    int ret;

    if (!PyArg_ParseTuple(args, "s", &key))
        return NULL;

    ret = isKeyPressed(key);
    return PyLong_FromLong(ret);
}

static PyObject *ARPGMaker_renderImage(PyObject *self, PyObject *args) {
    char *filePath;

    if (!PyArg_ParseTuple(args, "s", &filePath))
        return NULL;

    renderImage(filePath);
    Py_RETURN_NONE;
}

static PyMethodDef ARPGMakerMethods[] = {
    {"system",  ARPGMaker_system, METH_VARARGS, "Execute a shell command."},
    {"init", ARPGMaker_init, METH_VARARGS, ""},
    {"display", ARPGMaker_display, METH_VARARGS, ""},
    {"printHello", ARPGMaker_hello, METH_VARARGS, ""},
    {"close", ARPGMaker_close, METH_VARARGS, ""},
    {"systemEventHandler", ARPGMaker_systemEventHandler, METH_VARARGS, ""},
    {"isKeyPressed", ARPGMaker_isKeyPressed, METH_VARARGS, ""},
    {"renderImage", ARPGMaker_renderImage, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ARPGMakermodule = {
    PyModuleDef_HEAD_INIT,
    "ARPGMaker",
    NULL,
    -1,

    ARPGMakerMethods
};

PyMODINIT_FUNC
PyInit_ARPGMaker(void)
{
    return PyModule_Create(&ARPGMakermodule);
}
