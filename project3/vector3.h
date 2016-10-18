#ifndef VECTOR3_H
#define VECTOR3_H

class vector3 {

public:
    vector3();

    void zeros();

    // three components
    double comp[3];

    vector3(double x, double y, double z);

    double x() { return comp[0]; }
    double y() { return comp[1]; }
    double z() { return comp[2]; }

    //double vx() { return comp[0]; }
    //double vy() { return comp[1]; }
    //double vz() { return comp[2]; }

    // allows us to index in two different ways
    double &operator() (int index) { return comp[index]; }
    double &operator[] (int index) { return comp[index]; }
    vector3 &operator+=(double rhs);
    vector3 &operator+=(vector3 rhs);
    vector3 &operator*=(double rhs);
    vector3 &operator*=(vector3 rhs);
    vector3 &operator/=(double rhs);
    vector3 &operator/=(vector3 rhs);
    vector3 &operator-=(double rhs);
    vector3 &operator-=(vector3 rhs);

    double length_squared();
    double length();

};

inline vector3 operator+(vector3 lhs, double rhs){
    lhs += rhs;
    return lhs;
}

inline vector3 operator+(double lhs, vector3 rhs) {
    rhs += lhs;
    return rhs;
}

inline vector3 operator+(vector3 lhs, vector3 rhs) {
    lhs += rhs;
    return lhs;
}

inline vector3 operator*(vector3 lhs, double rhs){
    lhs *= rhs;
    return lhs;
}

inline vector3 operator*(double lhs, vector3 rhs) {
    rhs *= lhs;
    return rhs;
}

inline vector3 operator*(vector3 lhs, vector3 rhs) {
    lhs *= rhs;
    return lhs;
}

inline vector3 operator/(vector3 lhs, double rhs){
    lhs /= rhs;
    return lhs;
}

inline vector3 operator/(double lhs, vector3 rhs) {
    rhs /= lhs;
    return rhs;
}

inline vector3 operator/(vector3 lhs, vector3 rhs) {
    lhs /= rhs;
    return lhs;
}

inline vector3 operator-(vector3 lhs, double rhs){
    lhs -= rhs;
    return lhs;
}

inline vector3 operator-(double lhs, vector3 rhs) {
    rhs -= lhs;
    return rhs;
}

inline vector3 operator-(vector3 lhs, vector3 rhs) {
    lhs -= rhs;
    return lhs;
}

#endif // VECTOR3_H
