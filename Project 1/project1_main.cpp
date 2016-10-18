/*
When running this program, set input to be exponent between 1 and 7, 
i.e. ./'executable file' 1
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // converting input character to int
    int exponent = atoi(argv[1]);

    int base = 10;

    // vector size
    int n = pow(base, exponent);

    // calculate h value
    double h = 1.0/ (n + 1);

    // dynamic memory allocation
    double *a, *b, *c, *v, *k, *d, *b_tilde, *x;

    // arrays with n+2 elements, so boundary conditions are included
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
    b_tilde[0] = 0;

    // time CPU
    clock_t start, finish;           // declare start and final time 
    start = clock();                 // start clock

    // calculating forward substitution algorithm
    for (int i=1; i<n+1; i++){
        if (b_tilde[i-1] == 0){
            // calculating b_tilde special case
            b_tilde[i] = b[i];
        }
        else {
            b_tilde[i] = b[i] - (c[i-1] * a[i]) / b_tilde[i-1];
        }

        // substitution constant
        k[i] = a[i+1] / b_tilde[i];

        d[i] = d[i] - d[i-1] * k[i-1];
    }

    // initializing last and next to last value of vector v
     v[n+1] = 0;
     v[n] = d[n] / b_tilde[n];

    // calculating backward substituition algorithm
    for (int i=n; i>0; i--) {
        v[i] = (d[i] - c[i] * v[i+1]) / b_tilde[i];
    }

    finish = clock();               // end clock

    // print CPU time
    cout << ( (double) ( finish - start ) / ((double)CLOCKS_PER_SEC )) << endl;

    // calculating closed-form solution u(x) and epsilon
    for (int i=1; i<n+1; i++) {
        // creating u_i
        u[i] = 1.0 - (1.0 - exp(-10.0))*x[i] - exp(-10.0*x[i]);

        // calculating the error
        eps[i] = log10 ( abs( (v[i] - u[i]) / u[i] ) );
    }
    

    // creating files

    // we only want to create vector files for n=10 to n=1000
    if(n <= 1000){
        string outputfile ("vector_v");
        outputfile += argv[1];
        outputfile += ".txt";                    // making the file a .txt-file

        // creating files to add the second derivatives
        ofstream myfile;
        myfile.open(outputfile);

        // writing v values for each n to file
        for (int i=0; i<n+2; i++){
            myfile << v[i] << " " << endl;
        }
    }

    string outputfile_error ("error_");
    outputfile_error += argv[1];
    outputfile_error += ".txt";

    ofstream myfile_error;
    myfile_error.open(outputfile_error); 

    // writing epsilon values for each n to file
    for (int i=1; i<n+1; i++){
        myfile_error << eps[i] << endl;
    }


    // deleting from heap to free m
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
