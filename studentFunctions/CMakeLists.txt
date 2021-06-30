# add the library that runs
add_library(studentFunctions displayStudents.cpp)

set_property(TARGET studentFunctions PROPERTY VERSION "1.0.0")
set_property(TARGET studentFunctions PROPERTY SOVERSION "1")

target_include_directories(studentFunctions
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

#setting the install rules
install(TARGETS studentFunctions DESTINATION lib)
install(FILES studentFunctions.hpp DESTINATION include)