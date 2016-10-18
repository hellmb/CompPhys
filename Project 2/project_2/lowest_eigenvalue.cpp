#include <iostream>
#include <lowest_eigenvalue.h>

using namespace std;

// function for finding the lowest index of matrix A to find the right eigenvector for the ground state
int findLowestIndex(double **A, int N) {

    int lowestIndex = 0;
    double lowestVal = A[0][0];

    for(int i = 1; i < N; i++) {
        if(A[i][i] > lowestVal) {
            lowestIndex = i;
            lowestVal = A[i][i];
        }
    }

    return lowestIndex;
}
