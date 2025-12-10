# generated from rosidl_generator_py/resource/_idl.py.em
# with input from wujihand_msgs:srv/GetDiagnostics.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetDiagnostics_Request(type):
    """Metaclass of message 'GetDiagnostics_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('wujihand_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'wujihand_msgs.srv.GetDiagnostics_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_diagnostics__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_diagnostics__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_diagnostics__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_diagnostics__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_diagnostics__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetDiagnostics_Request(metaclass=Metaclass_GetDiagnostics_Request):
    """Message class 'GetDiagnostics_Request'."""

    __slots__ = [
        '_check_fields',
    ]

    _fields_and_field_types = {
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'joint_temperatures'
# Member 'error_codes'
import numpy  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetDiagnostics_Response(type):
    """Metaclass of message 'GetDiagnostics_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('wujihand_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'wujihand_msgs.srv.GetDiagnostics_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_diagnostics__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_diagnostics__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_diagnostics__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_diagnostics__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_diagnostics__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetDiagnostics_Response(metaclass=Metaclass_GetDiagnostics_Response):
    """Message class 'GetDiagnostics_Response'."""

    __slots__ = [
        '_system_temperature',
        '_input_voltage',
        '_joint_temperatures',
        '_error_codes',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'system_temperature': 'double',
        'input_voltage': 'double',
        'joint_temperatures': 'double[20]',
        'error_codes': 'uint32[20]',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 20),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint32'), 20),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.system_temperature = kwargs.get('system_temperature', float())
        self.input_voltage = kwargs.get('input_voltage', float())
        if 'joint_temperatures' not in kwargs:
            self.joint_temperatures = numpy.zeros(20, dtype=numpy.float64)
        else:
            self.joint_temperatures = kwargs.get('joint_temperatures')
        if 'error_codes' not in kwargs:
            self.error_codes = numpy.zeros(20, dtype=numpy.uint32)
        else:
            self.error_codes = kwargs.get('error_codes')

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.system_temperature != other.system_temperature:
            return False
        if self.input_voltage != other.input_voltage:
            return False
        if any(self.joint_temperatures != other.joint_temperatures):
            return False
        if any(self.error_codes != other.error_codes):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def system_temperature(self):
        """Message field 'system_temperature'."""
        return self._system_temperature

    @system_temperature.setter
    def system_temperature(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'system_temperature' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'system_temperature' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._system_temperature = value

    @builtins.property
    def input_voltage(self):
        """Message field 'input_voltage'."""
        return self._input_voltage

    @input_voltage.setter
    def input_voltage(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'input_voltage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'input_voltage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._input_voltage = value

    @builtins.property
    def joint_temperatures(self):
        """Message field 'joint_temperatures'."""
        return self._joint_temperatures

    @joint_temperatures.setter
    def joint_temperatures(self, value):
        if self._check_fields:
            if isinstance(value, numpy.ndarray):
                assert value.dtype == numpy.float64, \
                    "The 'joint_temperatures' numpy.ndarray() must have the dtype of 'numpy.float64'"
                assert value.size == 20, \
                    "The 'joint_temperatures' numpy.ndarray() must have a size of 20"
                self._joint_temperatures = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 20 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'joint_temperatures' field must be a set or sequence with length 20 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._joint_temperatures = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def error_codes(self):
        """Message field 'error_codes'."""
        return self._error_codes

    @error_codes.setter
    def error_codes(self, value):
        if self._check_fields:
            if isinstance(value, numpy.ndarray):
                assert value.dtype == numpy.uint32, \
                    "The 'error_codes' numpy.ndarray() must have the dtype of 'numpy.uint32'"
                assert value.size == 20, \
                    "The 'error_codes' numpy.ndarray() must have a size of 20"
                self._error_codes = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 20 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'error_codes' field must be a set or sequence with length 20 and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._error_codes = numpy.array(value, dtype=numpy.uint32)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetDiagnostics_Event(type):
    """Metaclass of message 'GetDiagnostics_Event'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('wujihand_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'wujihand_msgs.srv.GetDiagnostics_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_diagnostics__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_diagnostics__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_diagnostics__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_diagnostics__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_diagnostics__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetDiagnostics_Event(metaclass=Metaclass_GetDiagnostics_Event):
    """Message class 'GetDiagnostics_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<wujihand_msgs/GetDiagnostics_Request, 1>',
        'response': 'sequence<wujihand_msgs/GetDiagnostics_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['wujihand_msgs', 'srv'], 'GetDiagnostics_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['wujihand_msgs', 'srv'], 'GetDiagnostics_Response'), 1),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from wujihand_msgs.srv import GetDiagnostics_Request
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, GetDiagnostics_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'GetDiagnostics_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from wujihand_msgs.srv import GetDiagnostics_Response
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, GetDiagnostics_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'GetDiagnostics_Response'"
        self._response = value


class Metaclass_GetDiagnostics(type):
    """Metaclass of service 'GetDiagnostics'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('wujihand_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'wujihand_msgs.srv.GetDiagnostics')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_diagnostics

            from wujihand_msgs.srv import _get_diagnostics
            if _get_diagnostics.Metaclass_GetDiagnostics_Request._TYPE_SUPPORT is None:
                _get_diagnostics.Metaclass_GetDiagnostics_Request.__import_type_support__()
            if _get_diagnostics.Metaclass_GetDiagnostics_Response._TYPE_SUPPORT is None:
                _get_diagnostics.Metaclass_GetDiagnostics_Response.__import_type_support__()
            if _get_diagnostics.Metaclass_GetDiagnostics_Event._TYPE_SUPPORT is None:
                _get_diagnostics.Metaclass_GetDiagnostics_Event.__import_type_support__()


class GetDiagnostics(metaclass=Metaclass_GetDiagnostics):
    from wujihand_msgs.srv._get_diagnostics import GetDiagnostics_Request as Request
    from wujihand_msgs.srv._get_diagnostics import GetDiagnostics_Response as Response
    from wujihand_msgs.srv._get_diagnostics import GetDiagnostics_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
