// Python.h содержит все необходимые функции, для работы с объектами Python
#include <Python.h>

// Эту функцию мы вызываем из Python кода
static PyObject* addList_add(PyObject* self, PyObject* args){

  PyObject * listObj;

  // Входящие аргументы находятся в кортеже
  // В нашем случае есть только один аргумент - список, на который мы будем
  // ссылаться как listObj
  if (! PyArg_ParseTuple( args, "O", &listObj))
    return NULL;

  // Длина списка
  long length = PyList_Size(listObj);

  // Проходимся по всем элементам
  int i, sum =0;
  for(i = 0; i < length; i++){
    // Получаем элемент из списка - он также Python-объект
    PyObject* temp = PyList_GetItem(listObj, i);
    // Мы знаем, что элемент это целое число - приводим его к типу C long
    long elem = PyLong_AsLong(temp);
    sum += elem;
  }
  // Возвращаемое в Python-код значение также Python-объект
  // Приводим C long к Python integer
  return Py_BuildValue("i", sum);
}

// Документация
static char addList_docs[] =
    "add( ): add all elements of the list\n";

/*
Эта таблица содержит необходимую информацию о функциях модуля
<имя функции в модуле Python>, <фактическая функция>,
<ожидаемые типы аргументов функции>, <документация функции>
*/
static PyMethodDef addList_funcs[] = {
    {"add", (PyCFunction)addList_add, METH_VARARGS, addList_docs},
    {NULL, NULL, 0, NULL}
};

/*
addList имя модуля и это блок его инициализации.
<желаемое имя модуля>, <таблица информации>, <документация модуля>
*/
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "addList",
        "addList example module",
        -1,
        addList_funcs,
        NULL,
        NULL,
        NULL,
        NULL
};

PyObject*
PyInit_addList(void){
    PyObject *module = PyModule_Create(&moduledef);

    if (module == NULL)
        return NULL;

    PyModule_AddStringConstant(module, "__author__", "Chuck Norris <chack@my_world.me>");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    return module;
}
