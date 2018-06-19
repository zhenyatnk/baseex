#
#  Coverals cmake, function for switch on coverage mode to compile
#

macro(coveralls_turn_on_coverage)
    if(NOT (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
        AND (NOT "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
        AND (NOT "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang"))        
        message(FATAL_ERROR "Coveralls: Compiler ${CMAKE_C_COMPILER_ID} is not GNU gcc! Aborting... You can set this on the command line using CC=/usr/bin/gcc CXX=/usr/bin/g++ cmake <options> ..")
    endif()

    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(FATAL_ERROR "Coveralls: Code coverage results with an optimised (non-Debug) build may be misleading! Add -DCMAKE_BUILD_TYPE=Debug")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endmacro()