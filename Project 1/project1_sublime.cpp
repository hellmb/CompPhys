#include <iostream>
#include <cmath>
#include <fstream>		/* Library for file operations */

using namespace std;

int main() {
    // matrice size
    int n = 10;

    // calculate h value
    double h = 1.0/ (n + 1);

    // dynamic memory allocation, array with n+2 elements, see notes why
    double *a, *b, *c, *v, *k, *d, *b_tilde, *x;

    a = new double[n+2];
    b = new double[n+2];
    c = new double[n+2];
    v = new double[n+2];
    k = new double[n+2];
    d = new double[n+2];
    b_tilde = new double[n+2];
    x = new double[n+2];


    // dynamic memory allocation of u and epsilon
    double *u, *eps;
    u = new double[n+2];
    eps = new double[n+2];


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
        b[i] = 2.0;
        x[i] = i*h;
        d[i] = (h * h) * (100.0 * exp(-10 * x[i]) );
    }

    // initializing first element in b_tilde
    b_tilde[0] = 0.0;

    // loop to calculate the forward substitution algorithms
    for (int i=1; i<n+1; i++){
        if (b_tilde[i-1] == 0){
            // calculating b_tilde special case
            b_tilde[i] = b[i];
        }
        else {
            b_tilde[i] = b[i] - (c[i-1] * a[i]) / b_tilde[i-1];
        }

        k[i] = a[i+1] / b_tilde[i];
        d[i] = d[i] - d[i-1] * k[i-1];
    }

    // initializing last and next to last value of vector v
     v[n+1] = 0.0;
     v[n] = d[n] / b_tilde[n];

    // calculate v from highest value to lowest
    for (int i=n; i>0; i--) {
        v[i] = (d[i] - c[i] * v[i+1]) / b_tilde[i];
    }

    for (int i=1; i<n+1; i++) {
        // creating u_i
        u[i] = 1.0 - (1.0 - exp(-10.0))*x[i] - exp(-10.0*x[i]);

        // calculating the error
        eps[i] = log10 ( abs( (v[i] - u[i]) / u[i] ) );
    }

/*
    // creating files to add the second derivatives
    ofstream myfile;
    //myfile.open("vector_v10.txt");
    //myfile.open("vector_v100.txt");
    //myfile.open("vector_v1000.txt");

    // adding values for each n to files
    for (int i=0; i<n+2; i++){
        myfile << v[i] << " " << endl;
    }
*/

    // printing u_exact
    for (int i=0; i<n+2; i++){
        //cout << *(eps + i) << endl;
    }

/*
    // creating file to store error values -> find maximum value in python
    ofstream myfile;
    //myfile.open("error_10.txt");
    //myfile.open("error_100.txt");
    //myfile.open("error_1000.txt");
    //myfile.open("error_10000.txt");
    //myfile.open("error_100000.txt");

    for (int i=1; i<n+1; i++){
        myfile << eps[i] << endl;
        //cout << *(eps + i) << endl;
    }
*/

    // deleting from heap, make more efficient later!
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] v;
    delete [] k;
    delete [] d;
    delete [] b_tilde;
    delete [] x;
    delete [] u;

    return 0;
}
