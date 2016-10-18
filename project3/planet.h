#ifndef PLANET_H
#define PLANET_H

#include "vector3.h"

// class Planet -> stores position, velocity and mass by calling vector3 class
class Planet{
public:
    vector3 position;
    vector3 velocity;
    double mass;
    vector3 force;

    Planet(vector3 position, vector3 velocity, double mass);
    Planet(double x, double y, double z, double vx, double vy, double vz, double mass);
    void ResetForce();
};

#endif // PLANET_H
