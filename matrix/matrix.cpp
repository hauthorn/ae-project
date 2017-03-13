//
// Created by anders on 3/10/17.
//
#include <iostream>

using namespace std;


/**
 * multiply two matrices using standard implementation from CLRS (page 371)
 * This should be used as verification algorithm
 * @param a
 * @param b
 * @param columns
 * @param rows
 * @return
 */
int **matrixMultiplySimple(int **a, int **b, int n) {
    int** c = new int*[n];

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
 * This algorithm multiplies with the transpose in order to avoid cache misses
 * @param a
 * @param b (transposed)
 * @param n
 * @return
 */
int **matrixMultiplySimpleWithTransposed(int **a, int **b, const int n) {
    int** c = 0;
    c = new int*[n];

    for(int i=0; i < n; i++) {
        c[i] = new int[n];
        for (int j = 0; j < n; j++) {
            int temp = 0;

            for (int k = 0; k < n; k++)
                temp += a[i][k]*b[j][k];

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

    // ignore actual transpose
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

class SquareMatrixMultiply {
private:
    int **a, **b, **c;
    int n;
public:
    /**'
     *
     * @param a int[n][n]
     * @param b int[n][n]
     * @param n should be power of 2
     */
    SquareMatrixMultiply(int **a, int **b, int n) {
        this->a = a;
        this->b = b;
        this->n = n;
        this->c[n][n];

        for(int i = 0; i < n; i++)
            this->c[i] = new int[n];
    }

    /**
     *
     * @param x1 left most
     * @param x2 right most
     * @param y1 upper most
     * @param y2 lower most
     * @return
     */
    int recurse(int x1, int x2, int y1, int y2) {
        if(x2 == x1) {
            // access actual matrices here
            this->c[x1][y1] = this->a[x1][y1]*this->b[x1][y1];
        } else {
            this->recurse(x1, x2/2, y1, y2/2);
            this->recurse(x2/2,x2,y1,y2/2);
            this->recurse(x1/2,x2/2,y2/2,y2);
            this->recurse(x2/2,x2,y2/2,y2);
        }
    }

    void printMatrix() {
        for(int i = 0; i < this->n; i++) {
            for(int j = 0; j < this->n; j++) {
                cout << this->c[i][j] <<" ";
            }

            cout << endl;
        }
    }
};