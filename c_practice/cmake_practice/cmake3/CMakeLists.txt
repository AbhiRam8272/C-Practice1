cmake_minimum_required(VERSION 3.10)
project(cmake3 C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
	src/add.c
	src/sub.c
	src/mul.c	
)

set(TEST
	test/app.c
)

set(INCLUDE
	include/math.h
)

add_executable(cal ${SOURCES} ${TEST} ${INCLUDE})



