cmake_minimum_required(VERSION 3.15)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set default compile flags for GCC
if ((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") )
  # using Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fsanitize=address -pedantic -Wall -Wextra -Werror")
endif()

# set the project name
project(cplings 
    VERSION 0.01
    DESCRIPTION "Small exercises to get you used to reading and writing C++ code! Inspired by Rustlings"
    )


##############################################
# Create target and set properties
##############################################

set(SOURCE_DIR src)
set(TESTER_DIR tests)

# set the CMake dir
set(CPM_DOWNLOAD_LOCATION "cmake/CPM.cmake")
include(${CPM_DOWNLOAD_LOCATION})

# Specify dependencies
CPMAddPackage("gh:catchorg/Catch2@2.13.5")

# Including packages for safe_numerics
CPMAddPackage(NAME safe_numerics
  GIT_REPOSITORY https://github.com/boostorg/safe_numerics.git
  GIT_TAG boost-1.75.0 
  GIT_SHALLOW TRUE
  DOWNLOAD_ONLY YES)
CPMAddPackage("gh:boostorg/core#boost-1.75.0")
CPMAddPackage("gh:boostorg/config#boost-1.75.0")
CPMAddPackage("gh:boostorg/detail#boost-1.75.0")
CPMAddPackage("gh:boostorg/logic#boost-1.75.0")
CPMAddPackage("gh:boostorg/mp11#boost-1.75.0")
CPMAddPackage("gh:boostorg/preprocessor#boost-1.75.0")
CPMAddPackage("gh:boostorg/type_traits#boost-1.75.0")
CPMAddPackage("gh:boostorg/integer#boost-1.75.0")

set(EXERCISES_PATH "exercises")
set(BOOST_LIBS safe_numerics core config detail logic
    mp11 preprocessor type_traits integer)
set(UNIT_TESTING_LIBRARY Catch2)

# add each library to the include path
foreach(temp_lib ${BOOST_LIBS})
    if(${temp_lib}_ADDED)
        add_library(${temp_lib} INTERFACE IMPORTED)
        set(temp_include_dir "${${temp_lib}_SOURCE_DIR}")
        message(STATUS "For Boost lib ${temp_lib} including ${temp_include_dir}")
        target_include_directories(${temp_lib} INTERFACE "${temp_include_dir}/include")
    else()
        message(STATUS "OOPS: ${temp_lib} not added")
    endif()
endforeach()

# add the main tester
add_library(cplings OBJECT ${TESTER_DIR}/main_tester.cpp)
target_include_directories(cplings PUBLIC include)
target_link_libraries(cplings ${UNIT_TESTING_LIBRARY})

set(CHAPTERS
  01_variables
  02_functions
  03_if
  04_pointers_references
  05_classes
  06_raii
  07_containers
  08_ownership
  09_templates
  10_security
)

foreach(_test_case ${CHAPTERS})
  add_subdirectory (${EXERCISES_PATH}/${_test_case})
endforeach()

