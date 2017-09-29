#ifndef _CTOPYPLOT_TESTS_HPP_
#define _CTOPYPLOT_TESTS_HPP_

#include <QObject>
#include <QtTest>
#include <vector>
#include <iostream>
#include <complex>

// Classe à tester
#include <CTPP/CToPyPlot.hpp>

using namespace CTPP;

class CToPyPlotTests : public QObject
{
  Q_OBJECT

  private slots :

  void Int16Tests();
  void Int32Tests();
  void FloatTests();
  void DoubleTests();
  void CplxInt16Tests();
  void CplxInt32Tests();
  void CplxFloatTests();
  void CplxDoubleTests();
};

#endif // _CTOPYPLOT_TESTS_HPP_