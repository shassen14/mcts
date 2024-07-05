cmake_minimum_required(VERSION 3.27)
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

# creating mcts library
add_library(${PROJECT_NAME} src/mcts_defs.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen) 
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include
                                                  ${PROJECT_SOURCE_DIR}/src)
                                                  