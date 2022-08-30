cmake_minimum_required(VERSION 3.23)

project(Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trie src/main.cpp)

################################
# GTest
################################
ADD_SUBDIRECTORY (googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

if (MSVC)
    set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
endif  (MSVC)

################################
# Unit Tests
################################
# Add test cpp file

project(runUnitTests)
include_directories(inc)
add_executable( runUnitTests testgtest.cpp )
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )





