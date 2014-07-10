cmake_minimum_required(VERSION 2.8.3)
project(hitwall)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  message_runtime
  roscpp
  rospy
  std_msgs
  turtlesim
  kobuki_msgs
  nav_msgs
  sensor_msgs
  gazebo_msgs
  gazebo_ros
  gazebo
  tf
)

find_package(gazebo REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   geometry_msgs#   std_msgs
# )


#######################################
## Declare ROS messages and services ##
#######################################
generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
   kobuki_msgs
   nav_msgs
   sensor_msgs
   gazebo_msgs
   tf
)
###################################
## catkin specific configuration ##
###################################
catkin_package(
   DEPENDS gazebo_ros
   CATKIN_DEPENDS roscpp rospy std_msgs message_runtime geometry_msgs kobuki_msgs nav_msgs sensor_msgs gazebo_msgs tf
)


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS} ${SDFormat_INCLUDE_DIRS}
)

## Declare a cpp library
# add_library(hitwall
#   src/${PROJECT_NAME}/hitwall.cpp
# )

## Declare a cpp executable
# add_executable(hitwall_node src/hitwall_node.cpp)
add_executable(openloop src/openloop.cpp)
add_executable(frontsensor src/frontsensor.cpp)
add_executable(wheelodom src/wheelodom.cpp)
add_executable(kinectir src/kinectir.cpp)
add_executable(basic_follower src/basic_follower.cpp)
add_executable(hugwall src/hugwall.cpp)
add_executable(simwallsensor src/simwallsensor.cpp)
add_executable(wall_following src/wall_following.cpp)
add_executable(go_to_goal src/go_to_goal.cpp)
add_executable(virtual_trajectory_tracking src/virtual_trajectory_tracking.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(hitwall_node hitwall_generate_messages_cpp)
add_dependencies(openloop hitwall_generate_messages_cpp)
add_dependencies(frontsensor hitwall_generate_messages_cpp)
add_dependencies(wheelodom hitwall_generate_messages_cpp)
add_dependencies(kinectir hitwall_generate_messages_cpp)
add_dependencies(basic_follower basic_follower_generate_messages_cpp)
add_dependencies(hugwall hitwall_generate_messages_cpp)
add_dependencies(simwallsensor hitwall_generate_messages_cpp)
add_dependencies(wall_following hitwall_generate_messages_cpp)
add_dependencies(go_to_goal hitwall_generate_messages_cpp)
add_dependencies(virtual_trajectory_tracking hitwall_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(hitwall_node
#   ${catkin_LIBRARIES}
# )

 target_link_libraries(openloop ${catkin_LIBRARIES})
 target_link_libraries(frontsensor ${catkin_LIBRARIES})
 target_link_libraries(wheelodom ${catkin_LIBRARIES})
 target_link_libraries(kinectir ${catkin_LIBRARIES})
 target_link_libraries(basic_follower ${catkin_LIBRARIES})
 target_link_libraries(hugwall ${catkin_LIBRARIES})
 target_link_libraries(simwallsensor ${catkin_LIBRARIES})
 target_link_libraries(simwallsensor ${gazebo_LIBRARIES})
 target_link_libraries(go_to_goal ${catkin_LIBRARIES})
 target_link_libraries(wall_following ${catkin_LIBRARIES})
 target_link_libraries(virtual_trajectory_tracking ${catkin_LIBRARIES})

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS hitwall hitwall_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_hitwall.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
