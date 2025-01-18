#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "math_c.h"

static PyObject *py_factorial(PyObject *self, PyObject *args)
{
    long long n;
    if (!PyArg_ParseTuple(args, "L", &n))
    {
        return NULL;
    }

    unsigned long long result = c_factorial(n);
    if (result == 0)
    {
        PyErr_SetString(PyExc_ValueError, "Negative input not allowed for factorial");
        return NULL;
    }

    return PyLong_FromUnsignedLongLong(result);
}

static PyMethodDef math_methods[] = {
    {"factorial", py_factorial, METH_VARARGS, PyDoc_STR("Calculate the factorial of a number.")},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef math_module = {
    PyModuleDef_HEAD_INIT,
    "math_c",
    PyDoc_STR("A module that exports some math utilities"),
    -1,
    math_methods};

PyMODINIT_FUNC PyInit_math_c(void)
{
    return PyModule_Create(&math_module);
}
