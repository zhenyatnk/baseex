
# do not follow symlinks in file(GLOB_RECURSE ...)
cmake_policy(SET CMP0009 NEW)

file(GLOB_RECURSE GCDA_FILES "${PROJECT_BINARY_DIR}/*.gcda")
if(NOT GCDA_FILES STREQUAL "")
  file(REMOVE ${GCDA_FILES})
endif()
