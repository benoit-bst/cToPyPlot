cmake_minimum_required(VERSION 2.8)
project(CToPyPlot)

set(MAJOR 0)
set(MINOR 1)
set(PATCH 0)
set(VERSION ${MAJOR}.${MINOR}.${PATCH})

# Boost filesystem
find_package(Boost 1.49.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

find_package(PythonInterp 2.7 REQUIRED)

# macro to active ENABLE_CTPP defintion
macro( CTPP_flag)
  if( ENABLE_CTPP)
    add_definitions( -DENABLE_CTPP=1)
  endif()
endmacro()

# Check directory
if (EXISTS /tmp)
  if(EXISTS /tmp/.CTPP/DrawVector.py)
    MESSAGE(STATUS "/tmp/.CTPP ready")
  else()
    MESSAGE(STATUS "Create /tmp/.CTPP ")
    MESSAGE(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
    execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/scripts/initLibrary.py ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
  endif()
else()
  error("Dir : /tmp no exist... can't create /tmp/.CTPP")
endif()

# folder .CTPP for headers
set( CTTP_INCLUDE_DIR ${CMAKE_BINARY_DIR}/.CTPP CACHE INTERNAL "" FORCE)
file( REMOVE_RECURSE ${CTTP_INCLUDE_DIR})
include_directories( ${CTTP_INCLUDE_DIR} )

# Create linkPath with #include <CTPP/CToPyPlot.hpp>
set(header_linkpath ${CTTP_INCLUDE_DIR}/CTPP/CToPyPlot.hpp)
get_filename_component( destdir ${header_linkpath}  PATH )
file( MAKE_DIRECTORY ${destdir})
file( WRITE ${header_linkpath} "#include <${CMAKE_CURRENT_SOURCE_DIR}/src/CToPyPlot.hpp>")

set(sources
  src/CToPyPlot.cpp
)

set(headers
  src/CToPyPlot.hpp
)

# Library
add_library(CToPyPlot STATIC ${sources})
target_link_libraries(CToPyPlot ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

# Tests
add_subdirectory(tests)