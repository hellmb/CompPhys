#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <armadillo>
#include <string>

// header files
#include <stdlib.h>
#include <class_jacobi.h>
#include <time_armadillo.h>
#include <unit_test.h>
#include <lowest_eigenvalue.h>

using namespace std;
using namespace arma;


int main(int argc, char* argv[]) {

    // converting input character to float
    double omega_r = atof( argv[1] );

    // mesh points
    int N = 400;

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
        if( atoi(argv[2]) == 1 ){
            // potential for single electron
            V[i] = rho[i] * rho[i];
        }
        else if( atoi( argv[2]) == 2 ){
            // potential for two electrons, non-interacting
            V[i] = ( omega_r * omega_r * rho[i] * rho[i] );
        }
        else if( atoi(argv[2]) == 3 ){
            // potential for two electrons, interacting
            V[i] = ( omega_r * omega_r * rho[i] * rho[i] ) + (1.0 / rho[i]) ;
        }
        else {
            cout << "Input value not assignable" << endl;
            // exit code
            exit(-1);
        }

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

    clock_t start, finish;           // declare start and final time
    start = clock();                 // start clock

    // now, let's try our jacobi method!
    jacobi_method(A, R, N);

    finish = clock();               // end clock

    cout << "Time Jacobi method: " << ( (double) ( finish - start ) / ((double)CLOCKS_PER_SEC )) << endl;

    // calculating the time 'armadillo' use to find the eigenvalues
    time_armadillo(d, e, N);


    // eigenvalue unit test
    eigval_test(A, d, e, N);

    // orthogonality unit test
    orth_test(R, N);


    // array of diagonal elements to write to an eigenvalue file for sorting in Python
    double *diag = new double[N];

    for (int i = 0; i < N; i++){
        diag[i] = A[i][i];
    }

    // create eigenvectors for ground state
    double *R_ground = new double [N];

    // lowest index value of A, after similarity transformations
    int index = findLowestIndex(A,N);

   for (int i = 0; i < N; i++){
       R_ground[i] = fabs( R[i][index] * R[i][index] );
   }

    // write values to file based on the input argument
   if( atoi(argv[2]) == 1 ){
       ofstream myfile;
       myfile.open("eigenvalues.txt");
       for (int i = 0; i < N; i++){
           myfile << diag[i] << endl;
       }
       myfile.close();
   }
   else if( atoi( argv[2]) == 2 ){
       string out_ground ("ground_omega_");
       out_ground += argv[1];
       out_ground += ".txt";

       ofstream ground;
       ground.open(out_ground);

       for (int i = 0; i < N; i++){
           ground << R_ground[i] << endl;
       }
   }
   else if( atoi(argv[2]) == 3 ){
       string out_ground ("int_ground_omega_");
       out_ground += argv[1];
       out_ground += ".txt";

       ofstream ground;
       ground.open(out_ground);

       for (int i = 0; i < N; i++){
           ground << R_ground[i] << endl;
        }
   }

    // delete from HEAP to free memory
    delete [] rho;
    delete [] V;
    delete [] d;
    delete [] e;
    delete [] A;
    delete [] R;

    return 0;
}

