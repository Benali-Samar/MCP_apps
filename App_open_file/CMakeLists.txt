#Simple Cmakelists for a minimal cpp app

#Minimum required version of Cmake
cmake_minimum_required  (VERSION 3.15)

#setting the project name
project (MCP_App)

#specifiting the c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#specifiying the executable file.cpp/.c
add_executable (MCP_App MCP_App.cpp)

# install binary under usr/bin
install (TARGETS MCP_App DESTINATION bin)


