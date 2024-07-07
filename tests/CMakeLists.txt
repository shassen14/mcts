project(tests)

# Obtain all headers and sources in tests directory
file(GLOB_RECURSE glob_headers [a-z]*.hpp)
file(GLOB_RECURSE glob_sources [a-z]*.cpp)
set(headers ${headers} ${glob_headers})
set(sources ${sources} ${glob_sources})

# create executable where it automatically includes all the individual test files
add_executable(${PROJECT_NAME} ${headers} ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
                      ${GTEST_LIBRARIES}
                      mcts)

# valgrind.bash file move over to utilize to check for memory leaks
configure_file(valgrind.bash valgrind.bash COPYONLY)