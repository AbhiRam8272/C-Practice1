cmake_minimum_required(VERSION 3.10)
project(cmake3 C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        func/add.c
        func/sub.c
        func/mul.c
        func/div.c
)

set(TEST
        calculator.c calculator.h
)


add_executable(cal ${SOURCES} ${TEST} )

