cmake_minimum_required(VERSION 3.10)

#set the project name and version
project(sumClasses VERSION 1.0)

#set cmake variables for C and C++ compilers detection
set (CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")
set (CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")

#specify the C++ standard
set(CMAKE_CPP_STANDARD 14)
set(CMAKE_CPP_STANDARD_REQUIRED True)

#configure a header file to pass the version number to source code
configure_file(sumClassesConfig.hpp.in sumClasses.hpp)

#add the subdirectory with the extra functions
add_subdirectory(studentFunctions)
list(APPEND EXTRA_LIBS studentFunctions)

#add the executable
add_executable(sumClasses main.cpp)

#link the library
target_link_libraries(sumClasses PUBLIC studentFunctions)

#including the directory to the list of paths
target_include_directories(sumClasses PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/studentFunctions"
                          )

#install rules
install(TARGETS sumClasses DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/../sumClassesConfig.hpp" DESTINATION include)