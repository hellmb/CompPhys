#include <iostream>

using namespace std;

int main() {
    // matrice size
    int n = 10;

    // dynamic memory allocation, array with n elements
    float *a, *b, *c, *v, *k, *b_tilde, *d_tilde = new float[n];


    // loop to calculate the forward and backward substitution algorithms
    for (int i=0; i<n; i++){
        b_tilde[i] = b[i] - (c[i-1]*a[i])/b_tilde[i-1];
        v[i] = (d_tilde[i] - c[i]*v[i+1])/b_tilde[i];
        d_tilde[i] = d[i] - d[i-1]*k[i-1];
    }

    return 0;
}
