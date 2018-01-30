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
  compartmentReportMap.h
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
  compartmentReportMap.cpp
  spikeReportASCII.cpp
  spikeReportBinary.cpp
  spikeReportBluron.cpp
  spikeReportNEST.cpp
)

set(BRIONPLUGINS_LINK_LIBRARIES
  PRIVATE Lunchbox Keyv Servus vmmlib HighFive ${Boost_FILESYSTEM_LIBRARIES}
          ${Boost_REGEX_LIBRARIES} ${Boost_IOSTREAMS_LIBRARIES}
          ${CMAKE_THREADS_LIB_INIT}
)

set(BRIONPLUGINS_OMIT_LIBRARY_HEADER ON)
set(BRIONPLUGINS_OMIT_VERSION_HEADERS ON)
common_library(BrionPlugins)
