#include "planet.h"

// member functions for class Planet
Planet::Planet(vector3 pos, vector3 vel, double m){
    position = pos;
    velocity = vel;
    mass = m;
}

Planet::Planet(double x, double y, double z, double vx, double vy, double vz, double m){
    position = vector3(x, y, z);
    velocity = vector3(vx, vy, vz);
    mass = m;
}

void Planet::ResetForce(){
    // reset force for every new planet -> create new vector of zeros
    force.zeros();
}

