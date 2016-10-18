#include <iostream>
#include <armadillo>

using namespace arma;
using namespace std;

int main() {

    // changeable parameter n
    int n = 10;

    // creating a matrix A with n*n elements
    mat A(n, n);

    // creating two matrices L and U
    mat L, U;

    // time CPU
    clock_t start, finish;           // declare start and final time
    start = clock();

    // find the LU decomposition
    lu(L,U,A);



    finish = clock();
    cout << ( (double) ( finish - start ) / ((double)CLOCKS_PER_SEC )) << endl;


    return 0;
}
