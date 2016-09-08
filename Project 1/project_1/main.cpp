#include <iostream>
#include <cmath>
#include <fstream>		/* Library for file operations */

using namespace std;

int main() {
    // matrice size
    int n = 1000;

    // calculate h value
    double h = 1.0/ (n + 1);

    // dynamic memory allocation, array with n+2 elements, see notes why
    double *a, *b, *c, *f, *v, *k, *d, *b_tilde, *d_tilde, *x;

    a = new double[n+2];
    b = new double[n+2];
    c = new double[n+2];
    f = new double[n+2];
    v = new double[n+2];
    k = new double[n+2];
    d = new double[n+2];
    b_tilde = new double[n+2];
    d_tilde = new double[n+2];
    x = new double[n+2];

    // we need an extra element i a because of the (n+1) row
    for (int i=1; i<n+2; i++){
        a[i] = -1.0;
    }

    // the c-values only go to the n-1 row
    for (int i=1; i<n; i++){
        c[i] = -1.0;
    }

    // fill arrrays, calculate x, f and d_tilde
    for (int i=1; i<n+1; i++) {
        //a[i] = -1.0;
        b[i] = 2.0;
        //c[i] = -1.0;
        x[i] = i*h;
        f[i] = 100.0*exp(-10*x[i]);
        d[i] = (h*h)*f[i];
    }

    // initializing first element in b_tilde
    b_tilde[0] = 0.0;

    // loop to calculate the forward and backward substitution algorithms
    for (int i=1; i<n+1; i++){
        if (b_tilde[i-1] == 0){
            b_tilde[i] = b[i];
        }
        else {
            b_tilde[i] = b[i] - (c[i-1] * a[i]) / b_tilde[i-1];
        }

        k[i] = a[i+1] / b_tilde[i];
        d_tilde[i] = d[i] - d[i-1] * k[i-1];
    }

    // initializing last and next to last value of vector v
     v[n+1] = 0.0;
     v[n] = d_tilde[n] / b_tilde[n];

    // calculate v from highest value to lowest
    for (int i=n; i>0; i--) {
        v[i] = (d_tilde[i] - c[i] * v[i+1]) / b_tilde[i];
    }

    // creating files to add the second derivatives
    ofstream myfile;
    //myfile.open("vector_v10.txt");
    //myfile.open("vector_v100.txt");
    myfile.open("vector_v1000.txt");

    // adding values for each n to files
    for (int i=0; i<n+2; i++){
        myfile << v[i] << " " << endl;
    }


    // deleting from heap, make more efficient later!
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] f;
    delete [] v;
    delete [] k;
    delete [] d;
    delete [] d_tilde;
    delete [] b_tilde;
    delete [] x;

    return 0;
}
