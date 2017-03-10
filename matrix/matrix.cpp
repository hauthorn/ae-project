//
// Created by anders on 3/10/17.
//

#include <iostream>


using namespace std;


/**
 * multiply two matrices using standard implementation from CLRS (page 371)
 * @param a
 * @param b
 * @param columns
 * @param rows
 * @return
 */
int **matrixMultiply(int **a, int **b, int aColumns, int aRows, int bColumns, int bRows) {
    if(aColumns != bRows) {
        throw 20;
    } else {
        int** c = 0;
        c = new int*[aRows];

        for(int i=0; i < aRows; i++) {
            c[i] = new int[bColumns];
            for(int j=0; j < bColumns; j++) {
                c[i][j] = 0;
                for(int k = 0; k < aColumns; k++)
                    c[i][j] = c[i][j]+(a[i][k]*b[k][j]);
            }
        }

        return c;
    }
}

int main() {
    int **array;
    array = new int *[2];
    for(int i = 0; i <2; i++) {
        array[i] = new int[2];

        for(int j = 0; j < 2; j++) {
            array[i][j] = 2;
        }
    }

    int **array2;
    array2 = new int *[2];
    for(int i = 0; i <2; i++) {
        array2[i] = new int[2];

        for(int j = 0; j < 2; j++) {
            array2[i][j] = 2;
        }
    }


    int **c = matrixMultiply(array,array2,2,2,2,2);

    cout << c[0][1];
}
