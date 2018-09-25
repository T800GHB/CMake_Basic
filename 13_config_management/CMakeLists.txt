cmake_minimum_required (VERSION 2.8)

project (PowerDemo)

# Use following command will generate cache files at the source directory
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories("${PROJECT_SOURCE_DIR}")

# Add a configuration header file, to handle settings for source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
  )

# Whether to use self-made MathFunctions library or not.
option (USE_MYMATH
	   "Use provided math implementation" ON)

# Whether to add MathFunctions library in.
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

aux_source_directory(. DIR_SRCS)

add_executable (Power ${DIR_SRCS})
target_link_libraries (Power  ${EXTRA_LIBS})
