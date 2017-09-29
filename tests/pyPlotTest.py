#!/usr/bin/python

import matplotlib.pyplot as pyplot

# Test for int type
def intTest():

  # Data
  x = []
  x.append(1)
  x.append(2)
  x.append(3)
  x.append(4)
  x.append(5)

  y = []
  y.append(1)
  y.append(2)
  y.append(3)
  y.append(4)
  y.append(5)

  # pyplot
  pyplot.title("title int test")
  pyplot.xlabel("samples")
  pyplot.rcParams.update({'font.size': 10})
  pyplot.ylabel('Val', rotation='horizontal')
  titleVector = str("x label")
  pyplot.plot(x, y, color='green', linestyle='solid', linewidth=1, label=titleVector)
  pyplot.legend(loc=1, prop={'size':6})
  pyplot.grid()
  pyplot.legend(loc='upper right')
  pyplot.show()
  pyplot.close()

# Test for double type
def doubleTest():

  y = []
  y.append(1.0)
  y.append(2.3)
  y.append(3.2)
  y.append(4.0)
  y.append(10.65)

  # pyplot
  pyplot.title("title double test")
  pyplot.xlabel("samples")
  pyplot.rcParams.update({'font.size': 10})
  pyplot.ylabel('Val', rotation='horizontal')
  titleVector = str("x label")
  pyplot.plot(y, color='green', linestyle='solid', linewidth=1, label=titleVector)
  pyplot.legend(loc=1, prop={'size':6})
  pyplot.grid()
  pyplot.legend(loc='upper right')
  pyplot.show()
  pyplot.close()

if __name__ == '__main__':
  intTest()
  doubleTest()