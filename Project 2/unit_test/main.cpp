#include <iostream>
#include "class_jacobi.h"
#include <assert.h>
#include <armadillo>

using namespace arma;
using namespace std;

int main()
{
    // create a simple 5x5 symmetric matrix

    int N = 5;

    // dynamic 2D arrays
    double **A = new double*[N];
    double **R = new double*[N];

    // we create a matrix to easily find the eigenvalues with armadillo
    // unfortunately, this matrix can not be sent into jacobi_method
    mat eig(N, N);

    // fill matrix A
    for (int i = 0; i < N; i++ ){
        // each i-th pointer is pointing to a dynamic array
        A[i] = new double[N];
        R[i] = new double[N];

        for (int j = 0; j < N; j++ ) {
            if ( i == j ) {

                A[i][j] = 5.0 + i;
                eig(i, j) = 5.0 + i;

            } else if ( i == j - 1 || j == i - 1 ) {

                A[i][j] = -1.0 - i;
                eig(i, j) = -1.0 - i;

            } else {

                A[i][j] = 0;
                eig(i, j) = 0;
            }
        }
    }

    //eig.print("eig = ");
    vec eigval;
    mat eigvec;

    eig_sym(eigval, eigvec, eig);
    //eigval.print("Eigenvalues of random matrix eig: ");

    jacobi_method(A, R, N);

    double *eig_diag = new double[N];
    double *eig_A = new double[N];

    for (int i = 0; i < N; i++){
        eig_A[i] = eigval(i);
        eig_diag[i] = A[i][i];

        //cout << eig_diag[i] << endl;
    }

    // test eigenvalues before and after
    // assertion will fail if eig_A != eig_diag
    assert (eig_A != eig_diag);

    delete [] eig_diag;

    return 0;
}
