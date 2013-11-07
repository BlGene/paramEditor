# Try to find the ParamEditor librairies
#  PARAMEDITOR_FOUND - system has ParamEditor lib
#  PARAMEDITOR_INCLUDE_DIR - the ParamEditor include directory
#  PARAMEDITOR_LIBRARIES - Libraries needed to use ParamEditor

# Copyright (c) 2013, Max Argus
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

if (PARAMEDITOR_INCLUDE_DIR AND PARAMEDITOR_LIBRARIES)
  # Already in cache, be silent
  set(PARAMEDITOR_FIND_QUIETLY TRUE)
endif (PARAMEDITOR_INCLUDE_DIR AND PARAMEDITOR_LIBRARIES)

find_path(PARAMEDITOR_INCLUDE_DIR NAMES confitem.h PATHS ${PROJECT_SOURCE_DIR}/h)
find_library(PARAMEDITOR_LIBRARIES NAMES paramEditor PATHS ${PROJECT_SOURCE_DIR}/build)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PARAMEDITOR DEFAULT_MSG PARAMEDITOR_INCLUDE_DIR PARAMEDITOR_LIBRARIES)

mark_as_advanced(PARAMEDITOR_INCLUDE_DIR PARAMEDITOR_LIBRARIES)
