# MIT License
#
# Copyright (c) 2017-2025 Christian (graetz23@gmail.com)
#
set(cmake_version "3.23") # set cmake version

message("Running on CMake version ${cmake_version}")

cmake_minimum_required(VERSION ${cmake_version})

set(prj_name "PAXCC") # the prj name
set(prj_binary "paxcc") # the prj binary file
set(prj_version "0.5") # the prj version

project(${prj_name}) # prj name

message("Building ${prj_name} prj in version ${prj_version}")

add_executable(${prj_binary})

set(prj_src ".") # set variable for directory of source code

target_sources(${prj_binary}
  PRIVATE
    ${prj_src}/main.cpp
) # adding the main binary file

add_library(libpaxcc)

set(paxcc "libpaxcc") # set variable for directory of library
set(paxcc_src "${prj_src}/paxcc") # set variable for directory of library

target_sources(${paxcc}
  PRIVATE
    ${paxcc_src}/Attributes.cpp
    ${paxcc_src}/Children.cpp
    ${paxcc_src}/Factory.cpp
    ${paxcc_src}/Pax.cpp
    ${paxcc_src}/PaxMap.cpp
    ${paxcc_src}/Reader.cpp
    ${paxcc_src}/SubSet.cpp
    ${paxcc_src}/Writer.cpp

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      ${paxcc_src}
    FILES
      ${paxcc_src}/AAttribute.h
      ${paxcc_src}/AChildren.h
      ${paxcc_src}/AFactory.h
      ${paxcc_src}/APax.h
      ${paxcc_src}/ASubSet.h
      ${paxcc_src}/Attributes.h
      ${paxcc_src}/Children.h
      ${paxcc_src}/Pax.h
      ${paxcc_src}/paxcc.h
      ${paxcc_src}/PaxMap.h
      ${paxcc_src}/Reader.h
      ${paxcc_src}/SubSet.h
      ${paxcc_src}/Writer.h
) # adding all source and header files of the library

target_link_libraries(${prj_binary}
  PRIVATE
    ${paxcc}
) # linking libraries against the main binary
