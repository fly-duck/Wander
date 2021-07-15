
# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Set the project name
project (Sandbox)

find_package(Boost 1.50 REQUIRED regex date_time system filesystem thread graph)
include_directories(${BOOST_INCLUDE_DIRS})
# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(Sandbox ${SOURCES})

add_executable(Arrow category/world_is_a_arrow.cc)
add_executable(Memory memory/allocater.cc)
# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(Sandbox
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/algorithm_lib
)
target_link_libraries(Sandbox ${Boost_LIBRARIES})

message("boost lib: ${Boost_LIBRARIES}")
message("boost inc:${Boost_INCLUDE_DIR}")
