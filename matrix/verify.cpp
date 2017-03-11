//
// Created by anders on 3/10/17.
//
#include "matrix.cpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    bool printM = false;

    int **a, **b, *a1, *b1;
    int n = 1024;

    a = new int *[n];
    b = new int *[n];
    a1 = new int[n*n];
    b1 = new int[n*n];


    for(int i = 0; i < n; i++) {
        // init arrays
        a[i] = new int[n];
        b[i] = new int[n];

        for(int j = 0; j < n; j++) {
            int i1 = rand() % n;
            a[i][j] = i1;
            a1[n*i+j] = i1;

            int i2 = rand() % n;
            b[i][j] = i2;
            b1[(n*i)+j] = i2;
        }

    }

    if(printM) {
        // i is column, j is row
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }

            cout << endl;
        }


        cout << endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << b[i][j] << " ";
            }

            cout << endl;
        }

        cout << " a1 " << endl;

        for(int i = 0; i < n; i++) {
            for(int j=0; j < n; j++) {
                cout << a1[i*n+j] << " ";
            }
            cout << endl;
        }

        cout << endl;


        cout << " b1 " << endl;

        for(int i = 0; i < n; i++) {
            for(int j=0; j < n; j++) {
                cout << b1[i*n+j] << " ";
            }
            cout << endl;
        }

        cout << endl;


        cout << endl;
    }


    int **r1 = matrixMultiplySimple(a,b,n);
    int **r2 = matrixMultiplySimpleTranspose(a,b,n);
    int *r3 = matrixOneDimension(a1,b1,n);
    int *r4 = matrixOneDimensionTranspose(a1,b1,n);



    /**
     * verify algorithms
     */
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < n; j++) {
            if(r1[i][j] != r2[i][j]) {
                cout << "algorithms varies " << r1[i][j] << " " << r2[i][j] << endl;
            }

            if(r2[i][j] != r3[(i*n)+j]) {
                cout << "algorithm 2 and 3 varies" << endl;
            }


            if(r3[(i*n)+j] != r4[(i*n)+j]) {
                cout << "algorithm 3 and 4 varies" << endl;
            }
        }
    }

    if(printM) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << r1[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << r3[n*i+j] << " ";
            }

            cout << endl;
        }
    }

}
