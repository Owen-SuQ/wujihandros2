// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "wujihand_msgs/msg/detail/hand_state__struct.h"
#include "wujihand_msgs/msg/detail/hand_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool wujihand_msgs__msg__hand_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
    if (class_attr == NULL) {
      return false;
    }
    PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
    if (name_attr == NULL) {
      Py_DECREF(class_attr);
      return false;
    }
    PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
    if (module_attr == NULL) {
      Py_DECREF(name_attr);
      Py_DECREF(class_attr);
      return false;
    }

    // PyUnicode_1BYTE_DATA is just a cast
    assert(strncmp("wujihand_msgs.msg._hand_state", (char *)PyUnicode_1BYTE_DATA(module_attr), 29) == 0);
    assert(strncmp("HandState", (char *)PyUnicode_1BYTE_DATA(name_attr), 9) == 0);

    Py_DECREF(module_attr);
    Py_DECREF(name_attr);
    Py_DECREF(class_attr);
  }
  wujihand_msgs__msg__HandState * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // handedness
    PyObject * field = PyObject_GetAttrString(_pymsg, "handedness");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->handedness, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // system_temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "system_temperature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->system_temperature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // input_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "input_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->input_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // actual_positions
    PyObject * field = PyObject_GetAttrString(_pymsg, "actual_positions");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 20;
      double * dest = ros_message->actual_positions;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // target_positions
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_positions");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 20;
      double * dest = ros_message->target_positions;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // joint_temperatures
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_temperatures");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 20;
      float * dest = ros_message->joint_temperatures;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // error_codes
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_codes");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT32);
      Py_ssize_t size = 20;
      uint32_t * dest = ros_message->error_codes;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint32_t tmp = *(npy_uint32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint32_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // enabled
    PyObject * field = PyObject_GetAttrString(_pymsg, "enabled");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'enabled'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = 20;
      bool * dest = ros_message->enabled;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyBool_Check(item));
        bool tmp = (item == Py_True);
        memcpy(&dest[i], &tmp, sizeof(bool));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * wujihand_msgs__msg__hand_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HandState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("wujihand_msgs.msg._hand_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HandState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  wujihand_msgs__msg__HandState * ros_message = (wujihand_msgs__msg__HandState *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // handedness
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->handedness.data,
      strlen(ros_message->handedness.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "handedness", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // system_temperature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->system_temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "system_temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // input_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->input_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "input_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // actual_positions
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "actual_positions");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->actual_positions[0]);
    memcpy(dst, src, 20 * sizeof(double));
    Py_DECREF(field);
  }
  {  // target_positions
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "target_positions");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->target_positions[0]);
    memcpy(dst, src, 20 * sizeof(double));
    Py_DECREF(field);
  }
  {  // joint_temperatures
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "joint_temperatures");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->joint_temperatures[0]);
    memcpy(dst, src, 20 * sizeof(float));
    Py_DECREF(field);
  }
  {  // error_codes
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "error_codes");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT32);
    assert(sizeof(npy_uint32) == sizeof(uint32_t));
    npy_uint32 * dst = (npy_uint32 *)PyArray_GETPTR1(seq_field, 0);
    uint32_t * src = &(ros_message->error_codes[0]);
    memcpy(dst, src, 20 * sizeof(uint32_t));
    Py_DECREF(field);
  }
  {  // enabled
    PyObject * field = NULL;
    size_t size = 20;
    bool * src = ros_message->enabled;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      int rc = PyList_SetItem(field, i, PyBool_FromLong(src[i] ? 1 : 0));
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "enabled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
