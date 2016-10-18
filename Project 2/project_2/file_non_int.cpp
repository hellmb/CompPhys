#include <iostream>
#include <fstream>
#include <string>

using namespace std;   

void non_int_file(double *R_ground, char* argv[], int N){
    // write to file -> create header to do this
    string out_ground ("ground_omega_");
    out_ground += argv[1];
    out_ground += ".txt";

    ofstream ground;
    ground.open(out_ground);

    for (int i = 0; i < N; i++){
        ground << R_ground[i] << endl;
    }
}
