cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
 
project(googletest_download NONE)
 
include(ExternalProject)

ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "/Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_src"
  BINARY_DIR        "/Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
