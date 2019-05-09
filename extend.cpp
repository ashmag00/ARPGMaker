#include <Python.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "engine/main.h"
#include "engine/Map.h"

// Extend all developer-level functions to a Python module
// #1: Create method to read Python arguments and types and call the engine function
// #2: Add function call to the list of methods

static PyObject *ARPGMaker_init(PyObject *self, PyObject *args) {
    int resX;
    int resY;
    int tileSize;
    char *title;

    if (!PyArg_ParseTuple(args, "iiis", &resX, &resY, &tileSize, &title))
        return NULL;
        
    init(resX, resY, tileSize, title);
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

static PyObject *ARPGMaker_loadTexture(PyObject *self, PyObject *args) {
    char *filePath;

    if (!PyArg_ParseTuple(args, "s", &filePath))
        return NULL;

    loadTexture(filePath);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_loadTexturesFromFile(PyObject *self, PyObject *args) {
    char *filePath;

    if (!PyArg_ParseTuple(args, "s", &filePath))
        return NULL;

    loadTexturesFromFile(filePath);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_renderImage(PyObject *self, PyObject *args) {
    char *filePath;

    if (!PyArg_ParseTuple(args, "s", &filePath))
        return NULL;

    renderImage(filePath);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_draw(PyObject *self, PyObject *args) {
    draw();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_createEntity(PyObject *self, PyObject *args) {
    int posx;
    int posy;
    int radius;
    int ret;

    if (!PyArg_ParseTuple(args, "iii", &posx, &posy, &radius))
        return NULL;
    
    ret = createEntity(posx, posy, radius);
    return PyLong_FromLong(ret);
}

static PyObject *ARPGMaker_remEntity(PyObject *self, PyObject *args) {
    int entID;

    if (!PyArg_ParseTuple(args, "i", &entID))
        return NULL;

    remEntity(entID);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_createMap(PyObject *self, PyObject *args) {
    int tileSize;
    int tileX;
    int tileY;

    if (!PyArg_ParseTuple(args, "iii", &tileSize, &tileX, &tileY))
        return NULL;

    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_setTexture(PyObject *self, PyObject *args) {
    unsigned int id;
    char *texturePath;

    if (!PyArg_ParseTuple(args, "is", &id, &texturePath))
        return NULL;

    setTexture(id, texturePath);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_renderEntity(PyObject *self, PyObject *args) {
    unsigned int id;

    if (!PyArg_ParseTuple(args, "i", &id))
        return NULL;

    renderEntity(id);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_renderEntities(PyObject *self, PyObject *args) {
    renderEntities();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_move(PyObject *self, PyObject *args) {
    unsigned int id;
    int movex;
    int movey;

    if (!PyArg_ParseTuple(args, "iii", &id, &movex, &movey))
        return NULL;

    move(id, movex, movey);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_movef(PyObject *self, PyObject *args) {
    unsigned int id;
    int numx;
    int denx;
    int numy;
    int deny;

    if (!PyArg_ParseTuple(args, "iiiii", &id, &numx, &denx, &numy, &deny))
        return NULL;

    movef(id, numx, denx, numy, deny);
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_clear(PyObject *self, PyObject *args) {
    clear();
    Py_RETURN_NONE;
}

static PyObject *ARPGMaker_isOpen(PyObject *self, PyObject *args) {
    bool ret;

    ret = isOpen();
    return PyLong_FromLong(ret);
}

static PyObject *ARPGMaker_circleCollide(PyObject *self, PyObject *args) {
    int ent1ID;
    int ent2ID;
    bool ret;

    if (!PyArg_ParseTuple(args, "ii", &ent1ID, &ent2ID))
        return NULL;
    
    ret = circleCollide(ent1ID, ent2ID);
    return PyLong_FromLong(ret);
}

static PyObject *ARPGMaker_mousePositionX(PyObject *self, PyObject *args) {
    int ret;

    ret = mousePositionX();
    return PyLong_FromLong(ret);
}

static PyObject *ARPGMaker_mousePositionY(PyObject *self, PyObject *args) {
    int ret;

    ret = mousePositionY();
    return PyLong_FromLong(ret);
}

static PyObject *ARPGMaker_mouseLeftClick(PyObject *self, PyObject *args) {
    bool ret;

    ret = mouseLeftClick();
    return PyLong_FromLong(ret);
}

static PyMethodDef ARPGMakerMethods[] = {
    {"init", ARPGMaker_init, METH_VARARGS, "Initialize the engine"},
    {"display", ARPGMaker_display, METH_VARARGS, "Display all drawn items in buffer"},
    {"close", ARPGMaker_close, METH_VARARGS, "Close the game window"},
    {"systemEventHandler", ARPGMaker_systemEventHandler, METH_VARARGS, "Handle inputs and events"},
    {"isKeyPressed", ARPGMaker_isKeyPressed, METH_VARARGS, "Checks is a certain key is pressed"},
    {"renderImage", ARPGMaker_renderImage, METH_VARARGS, "Attach a texture to a sprite"},
    {"draw", ARPGMaker_draw, METH_VARARGS, "Draws sprite to the didplay buffer"},
    {"loadTexture", ARPGMaker_loadTexture, METH_VARARGS, "Load and store a texture"},
    {"loadTexturesFromFile", ARPGMaker_loadTexturesFromFile, METH_VARARGS, "Load and store multiple textures"},
    {"createEntity", ARPGMaker_createEntity, METH_VARARGS, "Create a new Entity"},
    {"remEntity", ARPGMaker_remEntity, METH_VARARGS, "Destroy an Entity"},
    {"createMap", ARPGMaker_createMap, METH_VARARGS, "Create a new Map"},
    {"setTexture", ARPGMaker_setTexture, METH_VARARGS, "Assign a texture to an Entity"},
    {"renderEntity", ARPGMaker_renderEntity, METH_VARARGS, "Attach an Entity to a sprite"},
    {"renderEntities", ARPGMaker_renderEntities, METH_VARARGS, "Draw all entities in the Map"},
    {"move", ARPGMaker_move, METH_VARARGS, "Move an Entity in the window"},
    {"movef", ARPGMaker_movef, METH_VARARGS, "Meve an Entity in the window precisely"},
    {"clear", ARPGMaker_clear, METH_VARARGS, "Clear the window"},
    {"isOpen", ARPGMaker_isOpen, METH_VARARGS, "Checks if the window is open"},
    {"circleCollide", ARPGMaker_circleCollide, METH_VARARGS, "Checks for collision between two entities"},
    {"mousePositionX", ARPGMaker_mousePositionX, METH_VARARGS, "Get mouse X position"},
    {"mousePositionY", ARPGMaker_mousePositionY, METH_VARARGS, "Get mouse Y position"},
    {"mouseLeftClick", ARPGMaker_mouseLeftClick, METH_VARARGS, "Check if mouse is being clicked"},
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
