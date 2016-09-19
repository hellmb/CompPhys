/*
When running this program, set input to be exponent between 1 and 6, 
i.e. ./'executable file' 1
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include "time.h"

using namespace std;

int main(int argc, char* argv[]) {
    // converting input character to int
    int exponent = atoi(argv[1]);

    int base = 10;

    // vector size
    int n = pow(base, exponent);

    // calculate h value
    double h = 1.0/ (n + 1);

    // dynamic memory allocation, array with n+2 elements, see notes why
    double *a, *b, *c, *v, *k, *d, *b_spec, *x;

    a = new double[n+2];
    b = new double[n+2];
    c = new double[n+2];
    v = new double[n+2];
    k = new double[n+2];
    d = new double[n+2];
    b_spec = new double[n+2];
    x = new double[n+2];

    // we need an extra element in a because of the (n+1) row
    for (int i=1; i<n+2; i++){
        a[i] = -1.0;
    }

    // one less element in c because these values only go to the (n-1) row
    for (int i=1; i<n; i++){
        c[i] = -1.0;
    }

    // fill arrays and calculating x and d
    for (int i=1; i<n+1; i++) {
        b[i] = 2.0;
        x[i] = i*h;
        d[i] = (h * h) * (100.0 * exp(-10 * x[i]) );
    }

    // initializing first element in b_tilde
    b_spec[0] = 0.0;

    // time CPU
    clock_t start, finish;           // declare start and final time 
    start = clock();                 // start clock

    // calculating forward substitution algorithm for the special case
    for (int i=1; i<n+1; i++){
        b_spec[i] = ( i + 1 ) / i;
    
        k[i] = - i / ( i + 1 );
        d[i] = d[i] - d[i-1] * k[i-1];
    }

    // initializing last and next to last value of vector v for the special case
     v[n+1] = 0.0;
     v[n] = ( d[n] * n ) / ( n + 1 );

    // calculate v from highest value to lowest
    for (int i=n; i>0; i--) {
        v[i] = ( d[i+1] + d[i] )/ b_spec[i];
    }


    finish = clock();                   // end clock

    // print CPU time
    cout << ( (double) ( finish - start ) / ((double)CLOCKS_PER_SEC )) << endl;


    // deleting from heap, make more efficient later!
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] v;
    delete [] k;
    delete [] d;
    delete [] b_spec;
    delete [] x;

    return 0;
}
