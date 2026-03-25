cmake_minimum_required(VERSION 3.24)
include(FetchContent)
option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)

FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/heads/main.zip)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(dsa_tests
	string_test.cpp)

target_link_libraries(dsa_tests PRIVATE GTest::GTest dsa)

add_test(dsa_gtests dsa_tests)
