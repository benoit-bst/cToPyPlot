if(ENABLE_TESTING)

  set(ENABLE_CTPP ON)
  CTPP_flag()

  find_package(Qt4 4.6.3 COMPONENTS QtCore QtTest REQUIRED)
  include(${QT_USE_FILE})

  unset( MOC_SOURCES)
  qt4_wrap_cpp( MOC_SOURCES CToPyPlotTests.hpp)
  add_executable( CToPyPlotTests CToPyPlotTests.cpp ${MOC_SOURCES})
  target_link_libraries( CToPyPlotTests ${QT_LIBRARIES} CToPyPlot)

endif()