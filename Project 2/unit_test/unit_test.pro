TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    class_jacobi.cpp

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lblas -llapack -larmadillo

