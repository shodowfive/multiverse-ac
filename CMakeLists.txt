cmake_minimum_required(VERSION 3.16)

set(MODULE_NAME "multiverse")
project(${MODULE_NAME} LANGUAGES CXX)

# Pull the official helper macros
include(${CMAKE_SOURCE_DIR}/cmake/macros/AC_ADD_MODULE.cmake OPTIONAL)
include(${CMAKE_SOURCE_DIR}/cmake/macros/AC_ADD_SCRIPT_MODULE.cmake OPTIONAL)

# Use the modern helper that registers into the static modules loader
if (COMMAND ac_add_module)
  ac_add_module(${MODULE_NAME}
    LINKING_TYPE STATIC
    SOURCES
      src/HelloWorld.cpp
      src/loader.cpp
      src/MultiverseCommands.cpp
  )
else()
  message(FATAL_ERROR "ac_add_module() macro not found; check your AzerothCore cmake/macros includes.")
endif()
