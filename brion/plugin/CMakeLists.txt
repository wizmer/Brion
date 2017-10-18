# Copyright (c) 2013-2017, EPFL/Blue Brain Project
#                          Daniel Nachbaur <daniel.nachbaur@epfl.ch>
#
# This file is part of Brion <https://github.com/BlueBrain/Brion>
#

set(BRIONPLUGINS_HEADERS
  compartmentReportBinary.h
  compartmentReportCommon.h
  compartmentReportDummy.h
  compartmentReportHDF5.h
  morphologyHDF5.h
  morphologySWC.h
  spikeReportASCII.h
  spikeReportBinary.h
  spikeReportBluron.h
  spikeReportNEST.h
)

set(BRIONPLUGINS_SOURCES
  compartmentReportBinary.cpp
  compartmentReportCommon.cpp
  compartmentReportDummy.cpp
  compartmentReportHDF5.cpp
  morphologyHDF5.cpp
  morphologySWC.cpp
  spikeReportASCII.cpp
  spikeReportBinary.cpp
  spikeReportBluron.cpp
  spikeReportNEST.cpp
)

set(BRIONPLUGINS_LINK_LIBRARIES
  PRIVATE Lunchbox Servus vmmlib HighFive ${Boost_FILESYSTEM_LIBRARIES}
          ${Boost_REGEX_LIBRARIES} ${CMAKE_THREADS_LIB_INIT}
)

if(TARGET Keyv)
  list(APPEND BRIONPLUGINS_HEADERS compartmentReportMap.h)
  list(APPEND BRIONPLUGINS_SOURCES compartmentReportMap.cpp)
  list(APPEND BRIONPLUGINS_LINK_LIBRARIES PRIVATE Keyv)
endif()

if(TARGET ZeroEQ)
  list(APPEND BRIONPLUGINS_HEADERS morphologyZeroEQ.h)
  list(APPEND BRIONPLUGINS_SOURCES morphologyZeroEQ.cpp)
  list(APPEND BRIONPLUGINS_LINK_LIBRARIES PRIVATE ZeroEQ)
endif()

set(BRIONPLUGINS_OMIT_LIBRARY_HEADER ON)
set(BRIONPLUGINS_OMIT_VERSION_HEADERS ON)
common_library(BrionPlugins)
