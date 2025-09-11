cmake_minimum_required(VERSION 3.16)

# Name of this module
set(SCRIPT_MODULE_NAME "mod_multiverse")

project(${SCRIPT_MODULE_NAME})

# Tell AzerothCore this is a scripts module (no external deps)
ac_add_script_module(${SCRIPT_MODULE_NAME}
  SOURCES
    src/HelloWorld.cpp
    src/loader.cpp
)