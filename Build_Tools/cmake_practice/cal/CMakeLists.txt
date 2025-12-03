cmake_minimum_required(VERSION 3.10)
project(cmake3 C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        src/add.c
        src/sub.c
        src/mul.c
	src/prime.c
	src/fibonacci.c
	src/div.c
	src/odd_even.c
)

set(TEST
        test/calculator.c
)


add_executable(cal ${SOURCES} ${TEST} )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

