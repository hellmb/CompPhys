#include <iostream>
#include <cmath>
#include "vector3.h"

using namespace std;

// empty vector
vector3::vector3(){
    zeros();
}
void vector3::zeros(){
    comp[0] = 0.0;
    comp[1] = 0.0;
    comp[2] = 0.0;
}

// member functions definitions -> goes into .cpp file
vector3::vector3(double x, double y, double z){
    comp[0] = x;
    comp[1] = y;
    comp[2] = z;
}

vector3 &vector3::operator+=(double rhs){
    comp[0] += rhs;
    comp[1] += rhs;
    comp[2] += rhs;
    return *this;
}

vector3 &vector3::operator+=(vector3 rhs){
    comp[0] += rhs[0];
    comp[1] += rhs[0];
    comp[2] += rhs[0];
    return *this;
}

vector3 &vector3::operator*=(double rhs){
    comp[0] *= rhs;
    comp[1] *= rhs;
    comp[2] *= rhs;
    return *this;
}

vector3 &vector3::operator*=(vector3 rhs){
    comp[0] *= rhs[0];
    comp[1] *= rhs[0];
    comp[2] *= rhs[0];
    return *this;
}

vector3 &vector3::operator/=(double rhs){
    comp[0] /= rhs;
    comp[1] /= rhs;
    comp[2] /= rhs;
    return *this;
}

vector3 &vector3::operator/=(vector3 rhs){
    comp[0] /= rhs[0];
    comp[1] /= rhs[0];
    comp[2] /= rhs[0];
    return *this;
}

vector3 &vector3::operator-=(double rhs){
    comp[0] -= rhs;
    comp[1] -= rhs;
    comp[2] -= rhs;
    return *this;
}

vector3 &vector3::operator-=(vector3 rhs){
    comp[0] -= rhs[0];
    comp[1] -= rhs[0];
    comp[2] -= rhs[0];
    return *this;
}

double vector3::length_squared(){
    return comp[0] * comp[0] + comp[1] * comp[1] + comp[2] * comp[2];
}

double vector3::length(){
    return sqrt(length_squared());
}
