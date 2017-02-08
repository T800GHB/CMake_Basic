set(APP_SRC main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${LINK_DIR})

message(STATUS "This is BINARY dir " ${EXECUTABLE_OUTPUT_PATH})

add_executable(main ${APP_SRC})
target_link_libraries(main hello)

install(TARGETS main 
RUNTIME DESTINATION bin)

