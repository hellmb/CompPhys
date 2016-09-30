#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <armadillo>
#include <stdlib.h>
#include <class_jacobi.h>
#include <time_armadillo.h>

using namespace std;
using namespace arma;

// function to print matrix
void matrix ( double **A, int N ) {
    for (int i = 0; i < N; i++ ){
        for (int j = 0; j < N; j++ ) {
            cout << setw(10) << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // mesh points are N+1
    int N = 100;

    // dynamic memory allocation of variables
    double *rho, *V, *d, *e;
    rho = new double [N];
    V = new double [N];
    d = new double [N];
    e = new double [N];

    // boundary condition for rho
    double rho_max = 6;

    // step length
    double h = rho_max / (N+1);

    // filling rho-array
    for (int i = 0; i < N; i++) {
        rho[i] = (i+1) * h;
    }

    // diagonal elements
    for (int i = 0; i < N; i++ ) {
        V[i] = rho[i] * rho[i];
        d[i] = 2.0 / ( h * h ) + V[i];
        e[i] = - 1.0 / ( h * h );
    }

    // dynamic 2D arrays
    double **A = new double*[N];
    double **R = new double*[N];

    // fill matrix A
    for (int i = 0; i < N; i++ ){          // column
        // each i-th pointer is pointing to a dynamic array
        A[i] = new double[N];
        R[i] = new double[N];

        for (int j = 0; j < N; j++ ) {     // row
            if ( i == j ) {
                A[i][j] = d[i];
            } else if ( i == j - 1 || j == i - 1 ) {
                A[i][j] = e[i];
            } else {
                A[i][j] = 0;
            }
        }
    }

    // matrix(B, N);

    // time CPU
    clock_t start, finish;           // declare start and final time
    start = clock();                 // start clock

    // now, let's try the jacobi method
    jacobi_method(A, R, N);

    finish = clock();               // end clock

    // print CPU time
    cout << "Time Jacobi method: " << ( (double) ( finish - start ) / ((double)CLOCKS_PER_SEC )) << endl;



    // array of diagonal elements -> easier to sort
    double *diag = new double[N];

    for (int i = 0; i < N; i++){
        diag[i] = A[i][i];
    }

    // create file for sorting in python
    if (N == 400) {
        ofstream myfile;
        myfile.open("eigenvalues.txt");
        for (int i = 0; i < N; i++){
            myfile << diag[i] << endl;
        }
        myfile.close();
    }

    // calculating the time 'armadillo' use to find the eigenvalues
    //time_armadillo(d, e, N);


    // delete from HEAP to free memory
    delete [] rho;
    delete [] V;
    delete [] d;
    delete [] e;
    delete [] A;
    delete [] R;

    return 0;
}

