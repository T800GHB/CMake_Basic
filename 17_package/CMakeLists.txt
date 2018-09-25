cmake_minimum_required (VERSION 2.8)

project (PowerDemo)
set (Power_VERSION_MAJOR 1)
set (Power_VERSION_MINOR 0)

include_directories("${PROJECT_SOURCE_DIR}")
# set (CMAKE_INCLUDE_CURRENT_DIR ON)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
  )

if (NOT HAVE_POW)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)  
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (NOT HAVE_POW)

aux_source_directory(. DIR_SRCS)

add_executable(Power ${DIR_SRCS})
target_link_libraries (Power  ${EXTRA_LIBS})

install (TARGETS Power DESTINATION bin)
install (FILES "${PROJECT_SOURCE_DIR}/config.h"
         DESTINATION include)

enable_testing()

add_test (test_run Power 5 2)

add_test (test_usage Power)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Power ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)
 
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")

# Construct a CPack install package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Power_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Power_VERSION_MINOR}")
include (CPack)
