// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from autopatrol_interfaces:srv/SpeechText.idl
// generated code does not contain a copyright notice
#include "autopatrol_interfaces/srv/detail/speech_text__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "autopatrol_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "autopatrol_interfaces/srv/detail/speech_text__struct.h"
#include "autopatrol_interfaces/srv/detail/speech_text__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // text
#include "rosidl_runtime_c/string_functions.h"  // text

// forward declare type support functions


using _SpeechText_Request__ros_msg_type = autopatrol_interfaces__srv__SpeechText_Request;

static bool _SpeechText_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SpeechText_Request__ros_msg_type * ros_message = static_cast<const _SpeechText_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: text
  {
    const rosidl_runtime_c__String * str = &ros_message->text;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _SpeechText_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SpeechText_Request__ros_msg_type * ros_message = static_cast<_SpeechText_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: text
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->text.data) {
      rosidl_runtime_c__String__init(&ros_message->text);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->text,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'text'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autopatrol_interfaces
size_t get_serialized_size_autopatrol_interfaces__srv__SpeechText_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SpeechText_Request__ros_msg_type * ros_message = static_cast<const _SpeechText_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->text.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _SpeechText_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_autopatrol_interfaces__srv__SpeechText_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autopatrol_interfaces
size_t max_serialized_size_autopatrol_interfaces__srv__SpeechText_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: text
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = autopatrol_interfaces__srv__SpeechText_Request;
    is_plain =
      (
      offsetof(DataType, text) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SpeechText_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_autopatrol_interfaces__srv__SpeechText_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SpeechText_Request = {
  "autopatrol_interfaces::srv",
  "SpeechText_Request",
  _SpeechText_Request__cdr_serialize,
  _SpeechText_Request__cdr_deserialize,
  _SpeechText_Request__get_serialized_size,
  _SpeechText_Request__max_serialized_size
};

static rosidl_message_type_support_t _SpeechText_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SpeechText_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autopatrol_interfaces, srv, SpeechText_Request)() {
  return &_SpeechText_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "autopatrol_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "autopatrol_interfaces/srv/detail/speech_text__struct.h"
// already included above
// #include "autopatrol_interfaces/srv/detail/speech_text__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SpeechText_Response__ros_msg_type = autopatrol_interfaces__srv__SpeechText_Response;

static bool _SpeechText_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SpeechText_Response__ros_msg_type * ros_message = static_cast<const _SpeechText_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    cdr << (ros_message->result ? true : false);
  }

  return true;
}

static bool _SpeechText_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SpeechText_Response__ros_msg_type * ros_message = static_cast<_SpeechText_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->result = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autopatrol_interfaces
size_t get_serialized_size_autopatrol_interfaces__srv__SpeechText_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SpeechText_Response__ros_msg_type * ros_message = static_cast<const _SpeechText_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SpeechText_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_autopatrol_interfaces__srv__SpeechText_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_autopatrol_interfaces
size_t max_serialized_size_autopatrol_interfaces__srv__SpeechText_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: result
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = autopatrol_interfaces__srv__SpeechText_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SpeechText_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_autopatrol_interfaces__srv__SpeechText_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SpeechText_Response = {
  "autopatrol_interfaces::srv",
  "SpeechText_Response",
  _SpeechText_Response__cdr_serialize,
  _SpeechText_Response__cdr_deserialize,
  _SpeechText_Response__get_serialized_size,
  _SpeechText_Response__max_serialized_size
};

static rosidl_message_type_support_t _SpeechText_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SpeechText_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autopatrol_interfaces, srv, SpeechText_Response)() {
  return &_SpeechText_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "autopatrol_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "autopatrol_interfaces/srv/speech_text.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SpeechText__callbacks = {
  "autopatrol_interfaces::srv",
  "SpeechText",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autopatrol_interfaces, srv, SpeechText_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autopatrol_interfaces, srv, SpeechText_Response)(),
};

static rosidl_service_type_support_t SpeechText__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SpeechText__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, autopatrol_interfaces, srv, SpeechText)() {
  return &SpeechText__handle;
}

#if defined(__cplusplus)
}
#endif
