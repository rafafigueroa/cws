cmake_minimum_required(VERSION 2.8.3)
project(vicon_stream)
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

add_executable(vicon_stream src/vicon_stream.cpp)
add_library(vicon_pos src/vicon_pos.cpp)
add_library(shared_memory_feedback src/shared_memory_feedback.cpp)
target_link_libraries(vicon_stream ${catkin_LIBRARIES})
target_link_libraries(vicon_stream vicon_pos)
target_link_libraries(vicon_stream shared_memory_feedback)
target_link_libraries(vicon_stream ViconDataStreamSDK_CPP)
target_link_libraries(vicon_stream pthread)
add_dependencies(vicon_stream vicon_stream_gencpp)
