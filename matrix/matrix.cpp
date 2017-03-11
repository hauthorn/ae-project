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
int **matrixMultiplySimple(int **a, int **b, int n) {
    int** c = 0;
    c = new int*[n];

    for(int i=0; i < n; i++) {
        c[i] = new int[n];

        for (int j = 0; j < n; j++) {
            int temp = 0;

            for (int k = 0; k < n; k++)
                temp += a[i][k] * b[k][j];

            c[i][j] = temp;
        }
    }

    return c;
}


/**
 * transpose an n*n matrix
 * @param src source matrix. Src is not modified
 * @param dst pointer to destination matrix
 * @param N
 */
void transpose(int **src, int **dst, const int N) {
    for(int i = 0; i<N; i++) {
        for(int j = 0; j < N; j++) {
            dst[j][i] = src[i][j];
        }
    }
}

/**
 * verified transpose1d
 * @param src
 * @param dst
 * @param N
 * @param M
 */
void transpose1d(int *src, int *dst, const int n) {
    for(int l = 0; l < n*n; l++) {
        int i = l / n;
        int j = l % n;
        dst[l] = src[n*j+i];
    }
}

/**
 * This algorithm multiplies with the transpose in order to avoid cache misses
 * @param a
 * @param b
 * @param n
 * @return
 */
int **matrixMultiplySimpleTranspose(int **a, int **b, const int n) {
    int** c = 0;
    c = new int*[n];

    int **t = new int*[n];

    for(int i = 0; i<n;i++) {
        t[i] = new int[n];
    }

    transpose(b,t,n);

    for(int i=0; i < n; i++) {
        c[i] = new int[n];
        for (int j = 0; j < n; j++) {
            int temp = 0;

            for (int k = 0; k < n; k++)
                temp += a[i][k]*t[j][k];

            c[i][j] = temp;
        }
    }

    return c;
}

/**
 * multiply vectors represented in 1 dimension
 * @param a
 * @param b
 * @param n
 * @return
 */
int *matrixOneDimension(int *a, int *b, const int n) {
    int *c = new int[n*n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp = 0;
            for(int k = 0; k < n; k++) {
                int aa = a[n*i+k];
                int bb = b[k*n+j];
                temp += aa*bb;
            }

            c[(n*i)+j] = temp;
        }
    }

    return c;
}

int *matrixOneDimensionTranspose(int *a, int *b, const int n) {
    int *t = new int[n*n]; // transposed matrix
    int *c = new int[n*n]; // result array

    transpose1d(b,t,n);

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            int tmp = 0;

            for(int k=0; k < n; k++) {
                int aa = a[(n*i)+k];
                int bb = t[(n*j)+k];
                tmp += aa*bb;
            }

            c[n*i+j] = tmp;
        }
    }

    return c;
}