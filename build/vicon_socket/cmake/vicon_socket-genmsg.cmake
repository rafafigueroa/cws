# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(WARNING "Invoking generate_messages() without having added any message or service file before.
You should either add add_message_files() and/or add_service_files() calls or remove the invocation of generate_messages().")
message(STATUS "vicon_socket: 0 messages, 0 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(vicon_socket_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_cpp(vicon_socket
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vicon_socket
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(vicon_socket_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(vicon_socket_generate_messages vicon_socket_generate_messages_cpp)

# target for backward compatibility
add_custom_target(vicon_socket_gencpp)
add_dependencies(vicon_socket_gencpp vicon_socket_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vicon_socket_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_lisp(vicon_socket
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vicon_socket
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(vicon_socket_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(vicon_socket_generate_messages vicon_socket_generate_messages_lisp)

# target for backward compatibility
add_custom_target(vicon_socket_genlisp)
add_dependencies(vicon_socket_genlisp vicon_socket_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vicon_socket_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_py(vicon_socket
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vicon_socket
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(vicon_socket_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(vicon_socket_generate_messages vicon_socket_generate_messages_py)

# target for backward compatibility
add_custom_target(vicon_socket_genpy)
add_dependencies(vicon_socket_genpy vicon_socket_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vicon_socket_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vicon_socket)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vicon_socket
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(vicon_socket_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(vicon_socket_generate_messages_cpp geometry_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vicon_socket)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vicon_socket
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(vicon_socket_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(vicon_socket_generate_messages_lisp geometry_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vicon_socket)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vicon_socket\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vicon_socket
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(vicon_socket_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(vicon_socket_generate_messages_py geometry_msgs_generate_messages_py)
