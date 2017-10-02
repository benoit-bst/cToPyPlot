# cToPyPlot

cToPyPlot is a C++ support library to the development. you can :

* Record raw datas vector in a file
* Print raw datas with python in a figure (matplotplib). IQ constellation available
* Recording the corresponding figure

Different types are supported :

* int16 or uint16
* int32 or uint32
* float
* double
* cplx int16 or cplx uint16
* cplx int32 or cplx uint32
* cplx float
* cplx double

Figures and raw datas are record in /tmp/.CTPP

# Examples

See associated tests

## Environment

Required tools and libraries

* cmake >= 3.0.2
* gcc >= 4.9.2
* python >= 2.7
* libqt4-dev >= 4.8.7
* boost filesystem >= 1.49
* matplotlib >= 1.49

debian installation 

```
apt-get install cmake g++ python libqt4-dev libboost-filesystem-dev python-matplotlib
```

## Source recovery

```
git clone https://github.com/benoit-bst/cToPyPlot
```

## Compilation

```
mkdir build
cd build
cmake -DENABLE_TESTING=ON ..
make
```

* `ENABLE_TESTING` activates tests compilation

## Run tests

```
cd tests 
./CToPyPlotTests
```

## Notes

It is possible to use #define for activating tests code (ENABLE_CTPP).
For that, add CTTP_flag() and set(ENABLE_CTPP ON) in Cmake file.

```c
#if ENABLE_CTPP

  std::vector< std::complex<double> > input;
  CToPyPlot::drawVector(CTPP::CplxDouble, input.data(), input.size());

#endif
```