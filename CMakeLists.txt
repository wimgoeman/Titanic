#Version 3.0 for C++11 features
cmake_minimum_required(VERSION 3.0) 

project("Titanic Client")

#Compile poco libraries
add_subdirectory(libs/poco)

set(SOURCES
    "src/main.cpp"
    "src/scanner/FileInfo.h"
    "src/scanner/FileInfo.cpp"
    "src/scanner/Scanner.cpp"
    "src/scanner/Scanner.h"
	"src/parser/Parser.h"
	"src/parser/Parser.cpp")

add_executable (titanic_client ${SOURCES})
target_link_libraries(titanic_client LINK_PRIVATE PocoFoundation)
target_compile_features(titanic_client PUBLIC cxx_auto_type)

