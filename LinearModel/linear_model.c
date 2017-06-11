#include <Python.h>
#include "linear_model.h"

/* LogisticRegression */
static void LR_dealloc(LogisticRegression* self){
    free(self -> weights);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject * LR_new(PyTypeObject *type, PyObject *args, PyObject *kwds){
    LogisticRegression *self;

    self = (LogisticRegression *)type->tp_alloc(type, 0);

    
    if (self != NULL) {
        self -> learning_rate = 0.1;

        self -> penalty = Py_None;
        if (self -> penalty == NULL) {
            Py_DECREF(self);
            return NULL;
        }

    }
    

    return (PyObject *)self;
}

static int LR_init(LogisticRegression *self, PyObject *args, PyObject *kwds){
    PyObject * penalty = NULL, *tmp;

    static char *kwlist[] = {"learning_rate", "penalty", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|dO", kwlist,
                                      &self->learning_rate, &penalty
                                      ))
        return NULL;

    if (penalty) {
        tmp = self->penalty;
        Py_INCREF(penalty);
        self->penalty = penalty;
        Py_XDECREF(tmp);
    }

    return 0;
}

static PyObject * LR_params(LogisticRegression *self){
    return Py_BuildValue("dO", self->learning_rate, self->penalty);
}

/* lr end */

static PyMethodDef module_methods[] = {
    {NULL}
};

#ifndef PyMODINIT_FUNC  
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
initlinear_model(void)
{
    PyObject* m;

    if (PyType_Ready(&LRType) < 0)
        return;

    m = Py_InitModule3("linear_model", module_methods,
                       "Example module that creates an extension type.");

    if (m == NULL)
        return;

    Py_INCREF(&LRType);
    PyModule_AddObject(m, "LogisticRegression", (PyObject *)&LRType);
}












