# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(WARNING "Invoking generate_messages() without having added any message or service file before.
You should either add add_message_files() and/or add_service_files() calls or remove the invocation of generate_messages().")
message(STATUS "hitwall: 0 messages, 0 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg;-Ikobuki_msgs:/opt/ros/hydro/share/kobuki_msgs/cmake/../msg;-Inav_msgs:/opt/ros/hydro/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/hydro/share/sensor_msgs/cmake/../msg;-Igazebo_msgs:/opt/ros/hydro/share/gazebo_msgs/cmake/../msg;-Itf:/opt/ros/hydro/share/tf/cmake/../msg;-Iactionlib_msgs:/opt/ros/hydro/share/actionlib_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/hydro/share/trajectory_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(hitwall_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_cpp(hitwall
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hitwall
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(hitwall_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(hitwall_generate_messages hitwall_generate_messages_cpp)

# target for backward compatibility
add_custom_target(hitwall_gencpp)
add_dependencies(hitwall_gencpp hitwall_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hitwall_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_lisp(hitwall
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hitwall
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(hitwall_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(hitwall_generate_messages hitwall_generate_messages_lisp)

# target for backward compatibility
add_custom_target(hitwall_genlisp)
add_dependencies(hitwall_genlisp hitwall_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hitwall_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_py(hitwall
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hitwall
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(hitwall_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(hitwall_generate_messages hitwall_generate_messages_py)

# target for backward compatibility
add_custom_target(hitwall_genpy)
add_dependencies(hitwall_genpy hitwall_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS hitwall_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hitwall)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/hitwall
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(hitwall_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(hitwall_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(hitwall_generate_messages_cpp kobuki_msgs_generate_messages_cpp)
add_dependencies(hitwall_generate_messages_cpp nav_msgs_generate_messages_cpp)
add_dependencies(hitwall_generate_messages_cpp sensor_msgs_generate_messages_cpp)
add_dependencies(hitwall_generate_messages_cpp gazebo_msgs_generate_messages_cpp)
add_dependencies(hitwall_generate_messages_cpp tf_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hitwall)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/hitwall
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(hitwall_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(hitwall_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(hitwall_generate_messages_lisp kobuki_msgs_generate_messages_lisp)
add_dependencies(hitwall_generate_messages_lisp nav_msgs_generate_messages_lisp)
add_dependencies(hitwall_generate_messages_lisp sensor_msgs_generate_messages_lisp)
add_dependencies(hitwall_generate_messages_lisp gazebo_msgs_generate_messages_lisp)
add_dependencies(hitwall_generate_messages_lisp tf_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hitwall)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hitwall\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/hitwall
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(hitwall_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(hitwall_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(hitwall_generate_messages_py kobuki_msgs_generate_messages_py)
add_dependencies(hitwall_generate_messages_py nav_msgs_generate_messages_py)
add_dependencies(hitwall_generate_messages_py sensor_msgs_generate_messages_py)
add_dependencies(hitwall_generate_messages_py gazebo_msgs_generate_messages_py)
add_dependencies(hitwall_generate_messages_py tf_generate_messages_py)
