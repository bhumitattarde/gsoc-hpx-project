cmake_minimum_required(VERSION 3.10)
project(gsoc-hpx-project) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(gsoc-hpx-project "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

target_include_directories(gsoc-hpx-project PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(gsoc-hpx-project PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.cpp"
)