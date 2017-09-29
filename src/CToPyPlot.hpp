#ifndef CToPyPlot_HPP
#define CToPyPlot_HPP

extern "C"
{
  #include <stdio.h>
  #include <stdlib.h>
}

#include <iostream>
#include <string>
#include <fstream>
#include <complex>

#include <boost/filesystem.hpp>

namespace CTPP {

// Data Type
enum dataType
{
  Int16 = 0,
  Int32,
  Float,
  Double,
  CplxInt16,
  CplxInt32,
  CplxFloat,
  CplxDouble
};

static std::string workDir = "/tmp/.CTPP"; // Work Directory
static const std::string vectorPath = workDir + "/tempVector.data"; // Raw Data

class CToPyPlot
{
  public:
    static void drawVector(dataType type, void* ptr, int nbData);
    static void recordFig(dataType type, void* ptr, int nbData, const char* title);
    static void recordRawData(dataType type, void* ptr, int nbData, const char* title);
    static void drawConstellation(dataType type, void* ptr, int nbData);
};

};

#endif // CToPyPlot_HPP