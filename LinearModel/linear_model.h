#include <Python.h>
#include "structmember.h"

typedef struct {
    PyObject_HEAD;
    double learning_rate;
    PyObject * penalty; /* L1, L2 regularization */
    double * weights;
    double b;
} LogisticRegression;

static void LR_dealloc(LogisticRegression* self);

static PyObject * LR_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

static int LR_init(LogisticRegression *self, PyObject *args, PyObject *kwds);

static PyObject * LR_params(LogisticRegression *self);


static PyMethodDef LR_methods[] = {
    {"get_params", (PyCFunction)LR_params, METH_NOARGS,
     "get all model params"
    },
    {NULL}  /* Sentinel */
};

static PyMemberDef LR_members[] = {
    {"learning_rate", T_OBJECT_EX, offsetof(LogisticRegression, learning_rate), 0,
     "learning_rate"},
    {"penalty", T_OBJECT_EX, offsetof(LogisticRegression, penalty), 0,
     "penalty"},
    {"b", T_DOUBLE, offsetof(LogisticRegression, b), 0,
     "b"},
    {NULL}  /* Sentinel */
};

static PyTypeObject LRType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "butterfly.linear_model.LogisticRegression",             /* tp_name */
    sizeof(LogisticRegression),             /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)LR_dealloc, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_compare */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "LogisticRegression objects",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    LR_methods,             /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)LR_init,      /* tp_init */
    0,                         /* tp_alloc */
    LR_new,                 /* tp_new */
};

/* LogisticRegression end */

