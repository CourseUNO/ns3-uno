#include <Python.h>
#include <stdlib.h>  // For strdup and free

// Define the Person structure
typedef struct {
    PyObject_HEAD
        char* name;
    int age;
} Person;

// Deallocation function to free resources
static void Person_dealloc(Person* self) {
    free(self->name);  // Free the dynamically allocated name string
    Py_TYPE(self)->tp_free((PyObject*)self);
}

// Initialization function (similar to Python's __init__)
static int Person_init(Person* self, PyObject* args, PyObject* kwds) {
    char* name;
    int age;
    if (!PyArg_ParseTuple(args, "si", &name, &age)) {
        return -1;  // Return -1 to indicate an error (e.g., invalid arguments)
    }
    self->name = strdup(name);  // Copy the input string
    if (self->name == NULL) {
        PyErr_SetString(PyExc_MemoryError, "Out of memory");
        return -1;
    }
    self->age = age;
    return 0;  // Success
}

// Greet method
static PyObject* Person_greet(Person* self) {
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "Hi, I am %s and I am %d years old", self->name, self->age);
    return PyUnicode_FromString(buffer);  // Return a Python string
}

// Method table for the Person type
static PyMethodDef Person_methods[] = {
    {"greet", (PyCFunction)Person_greet, METH_NOARGS, "Greet the person"},
    {NULL}  // Sentinel to mark the end of the array
};

// Define the Person type
static PyTypeObject PersonType = {
    PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "uno_extension.Person",       // Fully qualified name
    .tp_basicsize = sizeof(Person),     // Size of the object
    .tp_itemsize = 0,                   // For variable-sized objects (not used here)
    .tp_dealloc = (destructor)Person_dealloc,  // Deallocator
    .tp_flags = Py_TPFLAGS_DEFAULT,     // Default flags
    .tp_doc = "Person objects",         // Docstring for the type
    .tp_methods = Person_methods,       // Methods for the type
    .tp_init = (initproc)Person_init,   // Initialization function
    .tp_new = PyType_GenericNew,        // Use generic new function
};

// Module definition
static struct PyModuleDef uno_extension_definition = {
    PyModuleDef_HEAD_INIT,
    "uno_extension",                         // Module name
    "A module with a Person type",      // Module docstring
    -1,                                 // No per-interpreter state
    NULL                                // No module-level methods
};

// Module initialization function
PyMODINIT_FUNC PyInit_uno_extension(void) {
    PyObject* m;
    // Prepare the Person type
    if (PyType_Ready(&PersonType) < 0) {
        return NULL;
}

    // Create the module
    m = PyModule_Create(&uno_extension_definition);
    if (m == NULL) {
        return NULL;
}

    // Add the Person type to the module
    Py_INCREF(&PersonType);
    if (PyModule_AddObject(m, "Person", (PyObject*)&PersonType) < 0) {
        Py_DECREF(&PersonType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
