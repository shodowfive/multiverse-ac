cmake_minimum_required(VERSION 3.16)

# Name of this module
set(SCRIPT_MODULE_NAME "mod_multiverse")
project(${SCRIPT_MODULE_NAME} LANGUAGES CXX)

# Try to use AzerothCore's macro if it exists
if(NOT COMMAND ac_add_script_module)
  # Try to include the official macro from the AC tree
  if(EXISTS "${CMAKE_SOURCE_DIR}/cmake/macros/AC_ADD_SCRIPT_MODULE.cmake")
    include("${CMAKE_SOURCE_DIR}/cmake/macros/AC_ADD_SCRIPT_MODULE.cmake")
  endif()
endif()

# If still missing, define a minimal fallback so we can build
if(NOT COMMAND ac_add_script_module)
  include(CMakeParseArguments)  # cmake builtin
  function(ac_add_script_module name)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs SOURCES)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    add_library(${name} MODULE ${ARG_SOURCES})

    # Link to the core "game" target (AzerothCore builds it). If this fails,
    # change 'game' to 'worldserver' for older layouts.
    target_link_libraries(${name} PRIVATE game)

    # Make it look like an AC module (.mod, no lib prefix)
    set_target_properties(${name} PROPERTIES PREFIX "" SUFFIX ".mod")

    # Install into <install-prefix>/bin/modules
    install(TARGETS ${name} DESTINATION bin/modules)
  endfunction()
endif()

# Register your sources
ac_add_script_module(${SCRIPT_MODULE_NAME}
  SOURCES
    src/HelloWorld.cpp
    src/loader.cpp
)
