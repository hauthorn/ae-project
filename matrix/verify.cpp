//
// Created by anders on 3/10/17.
//
#include "matrix.cpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int **a, **b;
    int n = 10;

    a = new int *[n];
    b = new int *[n];

    for(int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
        for(int j = 0; j < n; j++) {
            a[i][j] = rand()%n;
            b[i][j] = rand()%n;
        }
    }

    int **r1 = matrixMultiplySimple(a,b,n);
    int **r2 = matrixMultiplySimpleTranspose(a,b,n);


    for(int i = 0; i<n; i++) {
        for(int j = 0; j < n; j++) {
            if(r1[i][j] != r2[i][j]) {
                cout << "algorithms varies " << r1[i][j] << " " << r2[i][j] << endl;
            } else {
                cout << r1[i][j] << " ";
            }

            cout << endl;
        }
    }

}
