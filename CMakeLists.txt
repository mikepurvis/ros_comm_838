cmake_minimum_required(VERSION 2.8.3)
project(ros_comm_838)
find_package(catkin REQUIRED COMPONENTS roscpp)
find_package(Boost REQUIRED COMPONENTS thread)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS} ${BOOST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${BOOST_LIBRARIES})
