set(LIB_LIST hello.cpp)
add_library(libhello ${LIB_LIST})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")
