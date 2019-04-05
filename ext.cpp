#include <Python.h>
#include <iostream>

using namespace std;

void printHello() {
    cout << "Hello World!" << endl;
}

static PyObject *spam_system(PyObject *self, PyObject *args) {
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}

// static PyObject *ext_printHello(PyObject *self, PyObject *args) {
//     if (!PyArg_ParseTuple(args, "s", NULL)) return NULL;
//     return Py_BuildValue("s", printHello(void));
// }

// static PyMethodDef extMethods[] = {
//     {"ext_printHello", (PyCFunction)ext_printHello, METH_VARARGS},
//     {NULL, NULL, 0, NULL}
// };

// static struct PyModuleDef hellomodule = {
//     PyModuleDef_HEAD_INIT,
//     "hello",
//     NULL,
//     -1,

//     extMethods
// };

// PyMODINIT_FUNC initest() {
//     return PyModule_Create(&hellomodule);
// }