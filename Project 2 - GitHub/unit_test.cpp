#include <iostream>
#include <armadillo>
#include <unit_test.h>

using namespace std;
using namespace arma;

// eigenvalue unit test
void eigval_test(double **A, double *d, double *e, int N){

    // 'armadillo' version of matrix A
    mat arma_A(N, N);

    // create armadillo matrix to find eigenvalues quickly
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j){
                arma_A(i, j) = d[i];
            }
            else if (i == j - 1 || j == i - 1) {
                arma_A(i, j) = e[i];
            }
            else {
                arma_A(i, j) = 0;
            }
        }
    }

    // eigenvalues of arma_A
    vec eigval = eig_sym(arma_A);

    // empty vector to store eigenvalues of matrix A
    vec jacobi_eig = zeros<vec>(N);

    for (int i = 0; i < N; i++) {
        // filling vector with eigenvalues
        jacobi_eig(i) = A[i][i];
    }

    // sorting jacobi_eig
    jacobi_eig = sort(jacobi_eig);

    // test if the eigenvalues are equal within a small tolerance
    if ( approx_equal( eigval, jacobi_eig, "absdiff", 1e-5 ) ) {
        cout << "Success! Eigenvalues are equal" << endl;
    }
    else {
        cout << "Error: eigenvalues not equal" << endl;
    }

}

// orthogonality unit test
void orth_test(double **R, int N){

    // 'armadillo' version of matrix R (eigenvectors)
    mat arma_R(N, N);

    // fill matrix with the same elements as matrix R
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            arma_R(i, j) = R[i][j];
        }
    }

    // identity matrix
    mat I = arma_R.t() * arma_R;

    // exact identity matrix
    mat I_exact = eye<mat>(N, N);

    // test to see if the two matrices are equal within a tolerance
    if ( approx_equal( I, I_exact, "absdiff", 1e-10 ) ){
        cout << "Success! Orthogonality and dot product preserved" << endl;
    }
    else{
        cout << "Error: orthogonality and dot product not preserve" << endl;
    }


}
