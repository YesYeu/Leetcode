cmake_minimum_required(VERSION 3.0.0)
project(algorithm_practice VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(algorithm_practice main.cpp test.cpp)
target_include_directories(algorithm_practice PRIVATE ${CMAKE_SOURCE_DIR}/leetcode)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
