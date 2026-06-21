cmake_minimum_required(VERSION 3.15)
project(nanograph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

add_library(nanograph
    src/storage_engine.cpp
    src/vector_index.cpp
    src/graph_engine.cpp
)

target_include_directories(nanograph PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(nanograph PRIVATE
        # Strict warnings to catch bugs early
        -Wall -Wextra -Wpedantic -Wshadow 
        
        # Maximum speed optimizations
        -O3 
        
        # Tells the compiler to use specific 
        # hardware instructions (like ARM NEON SIMD) for the current machine
        -march=native 
    )
endif()