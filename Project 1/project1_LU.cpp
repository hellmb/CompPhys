#include <iostream>
#include "armadillo"

using namespace arma;
using namespace std;

int main() {

	int n = 10;

	// creating a matrix A with n*n elements
	mat A(n, n); 

	// creating two matrices L and U
	mat L, U;

	// find the LU decomposition
	lu(L,U,A);

	L.print("L = ");


	return 0;
}