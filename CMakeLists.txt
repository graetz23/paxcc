# MIT License
#
# Copyright (c) 2017-2025 Christian (graetz23@gmail.com)
#
set(cmake_version "3.23") # set cmake version

message("Running on CMake version ${cmake_version}")

cmake_minimum_required(VERSION ${cmake_version})

set(prj_name "PAXCC") # the project name
set(prj_binary "example") # the project binary file
set(prj_version "0.5") # the project version

project(${prj_name}) # project name

message("Building ${prj_name} project in version ${prj_version}")

add_executable(${prj_binary})

set(prj_src ".") # set variable for directory of source code

target_sources(${prj_binary}
  PRIVATE
    ${prj_src}/main.cpp
) # adding the main binary file

set(paxcc "paxcc") # set variable for directory of library
set(paxcc_src "${prj_src}/paxcc") # set variable for directory of library

add_library(${paxcc})

target_sources(${paxcc}
  PRIVATE
    ${paxcc_src}/paxccAttributes.cpp
    ${paxcc_src}/paxccChildren.cpp
    ${paxcc_src}/paxccFactory.cpp
    ${paxcc_src}/paxccPax.cpp
    ${paxcc_src}/paxccPaxMap.cpp
    ${paxcc_src}/paxccReader.cpp
    ${paxcc_src}/paxccSubSet.cpp
    ${paxcc_src}/paxccWriter.cpp
    # adding the base system functions ..
    ${paxcc_src}/paxccSysError.cpp
    ${paxcc_src}/paxccSysException.cpp
    ${paxcc_src}/paxccSysFailure.cpp
    ${paxcc_src}/paxccSysStrTool.cpp
    ${paxcc_src}/paxccSysXmlHandler.cpp
    ${paxcc_src}/paxccSysXmlParser.cpp
    ${paxcc_src}/paxccSysXmlTool.cpp

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      ${paxcc_src}
    FILES
      ${paxcc_src}/paxccAAttribute.h
      ${paxcc_src}/paxccAChildren.h
      ${paxcc_src}/paxccAFactory.h
      ${paxcc_src}/paxccAPax.h
      ${paxcc_src}/paxccASubSet.h
      ${paxcc_src}/paxccAttributes.h
      ${paxcc_src}/paxccChildren.h
      ${paxcc_src}/paxccPax.h
      ${paxcc_src}/paxcc.h
      ${paxcc_src}/paxccPaxMap.h
      ${paxcc_src}/paxccReader.h
      ${paxcc_src}/paxccSubSet.h
      ${paxcc_src}/paxccWriter.h
      # adding the base system functions ..
      ${paxcc_src}/paxccSys.h
      ${paxcc_src}/paxccSysDefines.h
      ${paxcc_src}/paxccSysError.h
      ${paxcc_src}/paxccSysException.h
      ${paxcc_src}/paxccSysFailure.h
      ${paxcc_src}/paxccSysList.h
      ${paxcc_src}/paxccSysStrTool.h
      ${paxcc_src}/paxccSysXmlHandler.h
      ${paxcc_src}/paxccSysXmlParser.h
      ${paxcc_src}/paxccSysXmlTool.h

) # adding all source and header files of the library

target_link_libraries(${prj_binary}
  PRIVATE
    ${paxcc}
) # linking libraries against the main binary
