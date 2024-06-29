cmake_minimum_required(VERSION 3.5)
project(mcts
        VERSION 0.1.0
        DESCRIPTION "Just starting...
                     Monte Carlo Tree Search")


set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_BUILD_TYPE Debug)

find_package(Eigen3 3.3 REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(experiment)
add_subdirectory(tests)

