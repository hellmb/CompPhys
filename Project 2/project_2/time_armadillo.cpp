#include <iostream>
#include <armadillo> 
#include "time_armadillo.h"

using namespace arma;
using namespace std;

void time_armadillo(double *d, double *e, int N) {

    // creating NxN matrix
    mat A(N, N);

    // filling matrix A with same elements as in the main program
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++ ) {
            if ( i == j ) {
                A(i,j) = d[i];
            } else if ( i == j - 1 || j == i - 1 ) {
                A(i,j) = e[i];
            } else {
                A(i,j) = 0;
            }
        }
    }

    vec eigval;
    mat eigvec;

    // calculating how much time is needed to calculate the eigenvalues

    clock_t start, finish;           // declare start and final time
    start = clock();                 // start clock

    // built-in function from 'armadillo' to find the eigenvalues of matrix A
    eig_sym(eigval, eigvec, A);

    finish = clock();               // end clock

    // print CPU time
    cout << "Time 'armadillo': "<< ( (double) ( finish - start ) / ((double)CLOCKS_PER_SEC )) << endl;

    // printout to check that we got the right eigenvalues as the Jacobi method
    //eigval.print("Eigenvalues = ");
}
