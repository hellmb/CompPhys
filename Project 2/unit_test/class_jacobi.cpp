/*
 Jacobi's method for finding eigenvalues and eigenvector
 of the symmetric matrix A

 The eigenvalues will appear as the diagonal elements of A, A[i][i]

 The j-th components of the i-th eigenvector is stored in R[i][j]

 A is the input matrix
 R is the empty matrix for eigenvectors
 n is the dimension
*/

#include <iostream>
#include <cmath>
#include "class_jacobi.h"

using namespace std;


// function for finding the maximum off-diagonal matrix element
double maxoffdiag ( double **A, int &k, int &l, int n ) {

    double max = 0;

    // calculate maximum value of A -> create a more elegant algorithm for this later
    for ( int i = 0; i < n; i++ ){
        for ( int j = i + 1; j < n; j++ ) {
            if ( fabs( A[i][j] ) > max ) {
                max = fabs( A[i][j] );
                k = i;
                l = j;
            }
        }
    }

    return max;
}

// function for finding the values of cos and sin
void rotate ( double **A, double **R, int k, int l, int n ) {

    double c = INFINITY;
    double s = INFINITY;

    // loop to calculate the above variables
    if ( A[k][l] != 0 ) {
        double tau =( A[l][l] - A[k][k] ) / ( 2 * A[k][l] );

        // avoid loss of precision
        //double t = 1.0 / ( tau + sqrt( 1.0 + tau * tau ) );
        double t = -tau + sqrt(1 + tau*tau);
        if(tau <= 0) {
            // t = 1.0 / ( - tau + sqrt( 1.0 + tau * tau ) );
            t = -tau - sqrt(1 + tau*tau);
        }

        c = 1.0 / sqrt( 1.0 + t * t );
        s = t * c;
    }
    else {
        c = 1.0;
        s = 0;
    }

    // perform similarity transformation
    double a_kk = A[k][k];
    double a_ll = A[l][l];

    // new values for diagonal elements
    A[k][k] = ( a_kk * c * c ) + ( a_ll * s * s ) - ( 2.0 * A[k][l] * s * c );
    A[l][l] = ( a_ll * c * c ) + ( a_kk * s * s ) + ( 2.0 * A[k][l] * s * c );

    // set biggest non-diagonal elements to zero
    A[k][l] = 0.0;
    A[l][k] = 0.0;
    // and then we change the remaining elements
    for ( int i = 0; i < n; i++ ) {
        if ( i != k && i != l ) { 
            double a_ik = A[i][k];
            double a_il = A[i][l];
            A[i][k] = c*a_ik - s*a_il; 
            A[k][i] = A[i][k];

            A[i][l] = c*a_il + s*a_ik; 
            A[l][i] = A[i][l];
        }

        // Finally, we compute the new eigenvectors
        double r_ik = R[i][k];
        double r_il = R[i][l];
        R[i][k] = c*r_ik - s*r_il;
        R[i][l] = c*r_il + s*r_ik;
    }
}


// function for solving the Jacobi method
void jacobi_method (double **A, double **R, int n) {

    // create eigenvector matrix R --> can use armadillo to create this, compare flops later
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            // create if-test to fill the diagonal with 1 and the rest with 0
            if ( i == j ) {
                R[i][j] = 1.0;
            } else {
                R[i][j] = 0;
            }
        }
    }


    // tolerance
    double epsilon = 1.0E-8;
    // maximum number of iterations unknown -> try a number and make sure the actual number of iterations are smaller
    long max_iteration = n * n * n;
    // setting iteration to be 0 at first, and adding to it as we calculate
    long iteration = 0;

    int k, l;
    double max_offdiag = maxoffdiag ( A, k, l, n );

    while ( max_offdiag > epsilon && iteration < max_iteration ) {
        rotate ( A, R, k, l, n );
        max_offdiag = maxoffdiag( A, k, l, n );
        iteration ++;
    }

    cout << "Number of iterations: " << iteration << endl;

    return;
}





