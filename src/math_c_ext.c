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

static PyObject *py_fibsequence(PyObject *self, PyObject *args)
{
    long long n;
    if (!PyArg_ParseTuple(args, "L", &n))
    {
        return NULL;
    }

    if (n < 0)
    {
        PyErr_SetString(PyExc_ValueError, "Negative input not allowed");
        return NULL;
    }

    PyObject *ret = PyList_New(n);
    if (!ret)
    {
        return NULL;
    }

    if (n == 0)
    {
        return ret;
    }

    long long *fib_sequence = c_fibsequence(n);
    if (!fib_sequence)
    {
        goto error;
    }

    for (long long i = 0; i < n; i++)
    {
        PyObject *tmp = PyLong_FromLongLong(fib_sequence[i]);
        if (!tmp)
        {
            goto error;
        }
        PyList_SET_ITEM(ret, i, tmp);
    }

    goto end;

error:
    Py_XDECREF(ret);
    ret = NULL;
end:
    free(fib_sequence);
    return ret;
}

static PyMethodDef math_methods[] = {
    {"factorial", py_factorial, METH_VARARGS, PyDoc_STR("Calculate the factorial of a number.")},
    {"fibsequence", py_fibsequence, METH_VARARGS, PyDoc_STR("Get the fibsequence.")},
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
