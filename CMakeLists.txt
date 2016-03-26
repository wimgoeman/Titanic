cmake_minimum_required(VERSION 2.6)

project("Titanic Client")

message("cxx Flags: " ${CMAKE_CXX_FLAGS})

set(SOURCES
	"src/main.cpp"
	"src/Scanner/FileInfo.h"
	"src/Scanner/FileInfo.cpp")

add_executable (titanic_client ${SOURCES})