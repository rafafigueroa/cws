
cmake_minimum_required(VERSION 2.8.3)
project(vc_robots)
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs geometry_msgs message_generation)
#######################################
## Declare ROS messages and services ##
#######################################
generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
)
###################################
## catkin specific configuration ##
###################################
catkin_package(
   INCLUDE_DIRS include
   CATKIN_DEPENDS roscpp rospy std_msgs message_runtime geometry_msgs
)
###########
## Build ##
###########

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############

add_executable(tbot_vc src/tbot_vc.cpp)
add_library(shared_memory src/shared_memory.cpp)
target_link_libraries(tbot_vc shared_memory)
target_link_libraries(tbot_vc ${catkin_LIBRARIES})
target_link_libraries(tbot_vc pthread)
add_dependencies(tbot_vc vc_robots_gencpp)

add_executable(quad src/quad.cpp)
target_link_libraries(quad shared_memory)
target_link_libraries(quad ${catkin_LIBRARIES})
target_link_libraries(quad pthread)
add_dependencies(quad vc_robots_gencpp)


