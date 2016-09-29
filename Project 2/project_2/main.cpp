#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <class_jacobi.h>

using namespace std;

// function to print matrix
void matrix ( double **B, int N ) {
    for (int i = 0; i < N; i++ ){
        for (int j = 0; j < N; j++ ) {
            cout << setw(10) << B[i][j] << " ";
        }
        cout << endl;
    }
}

// compare function for sorting values
/*int comp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}*/

int main() {

    // mesh points are N+1
    int N = 100;

    // dynamic memory allocation of variables
    double *rho, *V, *d, *e;
    rho = new double [N];
    V = new double [N];
    d = new double [N];
    e = new double [N];
    double rho_max = 6;

    // boundary condition for rho
//    rho[0] = 0.0;
//    rho[N] = 6.0;

    // step length
    double h = rho_max / (N+1);

    // rho
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
    double **B = new double*[N];
    double **R = new double*[N];

    // fill matrix A
    for (int i = 0; i < N; i++ ){          // column
        // each i-th pointer is pointing to a dynamic array
        B[i] = new double[N];
        R[i] = new double[N];

        for (int j = 0; j < N; j++ ) {     // row
            if ( i == j ) {
                B[i][j] = d[i];
            } else if ( i == j - 1 || j == i - 1 ) {
                B[i][j] = e[i];
            } else {
                B[i][j] = 0;
            }
        }
    }

    // matrix(B, N);

    //    for (int i = 0; i < N+1; i++){
    //        cout << B[i][i] << endl;
    //    }

    //    for (int i = 0; i < N+1; i++){
    //        for (int j = 0; j < N+1; j++) {
    //            B[i][j] = 0;
    //        }
    //    }

    //    B[1][0] = 5;
    //    B[0][1] = B[1][0];
    //    B[0][0] = 1;
    //    B[1][1] = 3;
    //    B[2][2] = 1;

    // now, let's try the jacobi method
    jacobi_method(B, R, N);

    //    for (int i = 0; i < N+1; i++){
    //        for (int j = 0; j < N+1; j++) {
    //            cout << setw(10) << B[i][j] << " ";
    //        }
    //        cout << endl;
    //    }

    //    for (int i = 0; i < N+1; i++){
    //        for (int j = 0; j < N+1; j++) {
    //            cout << setw(10) << R[i][j] << " ";
    //        }
    //        cout << endl;
    //    }
    //    exit(1);

    // array of diagonal elements -> easier to sort
    double *diag = new double[N];

    for (int i = 0; i < N; i++){
        diag[i] = B[i][i];
    }

    for (int i = 0; i < N; i ++){
        cout << *(diag + i) << endl;
    }


    // sort values of diag array
    //qsort (diag, N+1, sizeof(double), comp);


    /*for (int i = 0; i < N+1; i ++){
        cout << *(diag + i) << endl;
    }*/
    //matrix(B,N);


    // delete from HEAP to free memory
    delete [] rho;
    delete [] V;
    delete [] d;
    delete [] B;
    delete [] R;

    return 0;
}

