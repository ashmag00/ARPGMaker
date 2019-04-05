#include <Python.h>
#include <iostream>

#include "engine/main.cpp"

using namespace std;

static PyObject *spam_system(PyObject *self, PyObject *args) {
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

static PyObject *spam_init(PyObject *self, PyObject *args) {
    int resX;
    int resY;
    string title;

    if (!PyArg_ParseTuple(args, "iis", &resX, &resY, &title))
        return NULL;
        
    init(resX, resY, title);
    Py_RETURN_NONE;
}

static PyObject *spam_display(PyObject *self, PyObject *args) {
    display();
    Py_RETURN_NONE;
}

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS, "Execute a shell command."},
    {"init", spam_init, METH_VARARGS, ""},
    {"display", spam_display, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    NULL,
    -1,

    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}
