set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_library(dsa STATIC
		string.cpp
		stack_allocator.cpp)

target_include_directories(dsa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
