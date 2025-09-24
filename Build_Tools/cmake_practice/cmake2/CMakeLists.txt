cmake_minimum_required(VERSION 3.10)
project(cmake2 C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
	test/app.c
	src/add.c
	include/math.h
)

add_executable(addition ${SOURCES} )
