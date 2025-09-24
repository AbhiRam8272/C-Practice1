cmake_minimum_required(VERSION 3.10)   # Minimum CMake version
project(cmake1 C)                   # Project name and language

set(CMAKE_C_STANDARD 11)               # Use C99 standard

# Add source files
set(SOURCES
    src/hello.c
)

# Create executable
add_executable(yoctotutor ${SOURCES})


