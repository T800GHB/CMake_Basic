set(LIB_LIST hello.cpp)
add_definitions("-DLIBHELLO_BULID")
add_library(libhello SHARED ${LIB_LIST})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")

install(TARGETS libhello
LIBRARY DESTINATION lib)