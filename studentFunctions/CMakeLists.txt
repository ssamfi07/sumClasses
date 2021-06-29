# add the library that runs
add_library(studentFunctions displayStudents.cpp)

set_property(TARGET studentFunctions PROPERTY VERSION "1.0.0")
set_property(TARGET studentFunctions PROPERTY SOVERSION "1")