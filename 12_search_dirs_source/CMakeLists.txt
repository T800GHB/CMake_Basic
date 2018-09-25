cmake_minimum_required (VERSION 2.8)

project (PowerDemo)

# Search all source files in the specific directory,
# save this directory as argument DIR_SRCS
aux_source_directory(. DIR_SRCS)

add_subdirectory(math)

add_executable(Power ${DIR_SRCS})

# Add linked libraries
target_link_libraries(Power MathFunctions)