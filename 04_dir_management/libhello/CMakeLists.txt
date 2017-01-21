set(LIB_LIST hello.cpp)
add_library(libhello ${LIB_LIST})
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")