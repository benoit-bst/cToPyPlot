#include "CToPyPlotTests.hpp"

QTEST_MAIN(CToPyPlotTests);

void CToPyPlotTests::Int16Tests()
{
  // Input
  int nbVal = 100;
  std::vector<short> input;
  for (int i = 0; i < nbVal; ++i){
    input.push_back(i);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::Int16, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::Int16, input.data(), input.size(), "figInt16");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::Int16, input.data(), input.size(), "Int16.data");
#endif
}

void CToPyPlotTests::Int32Tests()
{
  // Input
  int nbVal = 1000000;
  std::vector<int> input;
  for (int i = 0; i < nbVal; ++i){
    input.push_back(i+20000000);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::Int32, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::Int32, input.data(), input.size(), "figInt32");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::Int32, input.data(), input.size(), "Int32.data");
#endif
}

void CToPyPlotTests::FloatTests()
{
  // Input
  int nbVal = 1000;
  std::vector<float> input;
  for (int i = 0; i < nbVal; ++i){
    input.push_back(i);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::Float, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::Float, input.data(), input.size(), "figFloat");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::Float, input.data(), input.size(), "Float.data");
#endif
}

void CToPyPlotTests::DoubleTests()
{
  // Input
  int nbVal = 100;
  std::vector<double> input;
  for (int i = 0; i < nbVal; ++i){
    input.push_back(i);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::Double, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::Double, input.data(), input.size(), "figDouble");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::Double, input.data(), input.size(), "Double.data");
#endif
}

void CToPyPlotTests::CplxInt16Tests()
{
  // Input
  int nbVal = 100;
  std::vector<std::complex<short> > input;
  for (int i = 0; i < nbVal; ++i){
    std::complex<short> cplx(0, i);
    input.push_back(cplx);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::CplxInt16, input.data(), input.size());

  // Draw Constellation
  CToPyPlot::drawConstellation(CTPP::CplxInt16, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::CplxInt16, input.data(), input.size(), "figCplxInt16");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::CplxInt16, input.data(), input.size(), "CplxInt16.data");
#endif
}

void CToPyPlotTests::CplxInt32Tests()
{
  // Input
  int nbVal = 100;
  std::vector<std::complex<int> > input;
  for (int i = 0; i < nbVal; ++i){
    std::complex<int> cplx(0, i);
    input.push_back(cplx);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::CplxInt32, input.data(), input.size());

  // Draw Constellation
  CToPyPlot::drawConstellation(CTPP::CplxInt32, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::CplxInt32, input.data(), input.size(), "figCplxInt32");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::CplxInt32, input.data(), input.size(), "CplxInt32.data");
#endif
}

void CToPyPlotTests::CplxFloatTests()
{
  // Input
  int nbVal = 100;
  std::vector<std::complex<float> > input;
  for (int i = 0; i < nbVal; ++i){
    std::complex<float> cplx(0, i);
    input.push_back(cplx);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::CplxFloat, input.data(), input.size());

  // Draw Constellation
  CToPyPlot::drawConstellation(CTPP::CplxFloat, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::CplxFloat, input.data(), input.size(), "figCplxFloat");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::CplxFloat, input.data(), input.size(), "CplxFloat.data");
#endif
}

void CToPyPlotTests::CplxDoubleTests()
{
  // Input
  int nbVal = 100;
  std::vector<std::complex<double> > input;
  for (int i = 0; i < nbVal; ++i){
    std::complex<double> cplx(0, i);
    input.push_back(cplx);
  }

#if ENABLE_CTPP
  // Draw Vector
  CToPyPlot::drawVector(CTPP::CplxDouble, input.data(), input.size());

  // Draw Constellation
  CToPyPlot::drawConstellation(CTPP::CplxDouble, input.data(), input.size());

  // Record fig
  CToPyPlot::recordFig(CTPP::CplxDouble, input.data(), input.size(), "figCplxDouble");

  // Record Raw Data
  CToPyPlot::recordRawData(CTPP::CplxDouble, input.data(), input.size(), "CplxDouble.data");
#endif
}