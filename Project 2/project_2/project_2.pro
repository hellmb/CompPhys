TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

SOURCES += class_jacobi.cpp

SOURCES += time_armadillo.cpp

SOURCES += unit_test.cpp

SOURCES += lowest_eigenvalue.cpp

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lblas -llapack -larmadillo

