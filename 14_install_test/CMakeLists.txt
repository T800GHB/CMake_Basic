cmake_minimum_required (VERSION 2.8)

project (PowerDemo)

# Add support for gdb debug
set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Add supoort for C++ 11 standard
set(CMAKE_CXX_STANDARD 11)

# set (CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${PROJECT_SOURCE_DIR})

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
  )
 
option (USE_MYMATH
	   "Use provided math implementation" ON)

if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

aux_source_directory(. DIR_SRCS)

add_executable(Power ${DIR_SRCS})
target_link_libraries (Power  ${EXTRA_LIBS})

# Specify destination path to install
# As default, executable file will copy to /usr/local/bin
# header file will copy to /usr/local/include.
# or user could specify path to install
set(CMAKE_INSTALL_PREFIX /tmp)
install (TARGETS Power DESTINATION bin)
install (FILES "${PROJECT_SOURCE_DIR}/config.h"
         DESTINATION include)

# Enable test
enable_testing()

# Whether the test program could run successfully
add_test (test_run Power 5 2)

# To test whether the help information could provide as normal.
add_test (test_usage Power)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# To test square of 5
# add_test (test_5_2 Power 5 2)

# set_tests_properties (test_5_2
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

# To test 5 square of 10
# add_test (test_10_5 Power 10 5)

# set_tests_properties (test_10_5
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")

# To test 10 square of 2
# add_test (test_2_10 Power 2 10)

# set_tests_properties (test_2_10
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")

# To define a macro, simplify the procedure
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Power ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# 利用 do_test 宏，测试一系列数据
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")
