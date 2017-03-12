//
// Created by anders on 3/12/17.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

/**
 * represents the corners of the matrix
 */
typedef struct { int ra, rb, ca, cb; } corners; // for tracking rows and columns.

// set A[a] = k
void set(int **A, corners a, int k){
    int i, j;
    for(i=a.ra;i<a.rb;i++)
        for(j=a.ca;j<a.cb;j++)
            A[i][j] = k;
}

// set A[a] = [random(l..h)].
void randk(int **A, corners a, int l, int h){
    int i,j;
    for(i=a.ra;i<a.rb;i++)
        for(j=a.ca;j<a.cb;j++)
            A[i][j] = l + rand()% h;
}

// Return 1/4 of the int**rix: top/bottom , left/right.
void find_corners(corners a, int i, int j, corners *b) {
    int rm = a.ra + (a.rb - a.ra)/2;
    int cm = a.ca + (a.cb - a.ca)/2;
    *b = a;
    if (i==0)  b->rb = rm;     // top rows
    else       b->ra = rm;     // bot rows
    if (j==0)  b->cb = cm;     // left cols
    else       b->ca = cm;     // right cols
}

// Naive Multiply: A[a] * B[b] => C[c], recursively.
void mul(int** A, int** B, int** C, corners a, corners b, corners c) {
    corners aii[2][2], bii[2][2], cii[2][2];
    int i, j, m, n, p;

    // Check: A[m n] * B[n p] = C[m p]
    m = a.rb - a.ra; assert(m==(c.rb-c.ra));
    n = a.cb - a.ca; assert(n==(b.rb-b.ra));
    p = b.cb - b.ca; assert(p==(c.cb-c.ca));
    assert(m>0);

    if (n==1) {
        C[c.ra][c.ca] += A[a.ra][a.ca] * B[b.ra][b.ca];
        return;
    }

    // Create the smaller int**rices:
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            find_corners(a, i, j, &aii[i][j]);
            find_corners(b, i, j, &bii[i][j]);
            find_corners(c, i, j, &cii[i][j]);
        }
    }

    // Now do the 8 sub int**rix multiplications.
    // C00 = A00*B00 + A01*B10
    // C01 = A00*B01 + A01*B11
    // C10 = A10*B00 + A11*B10
    // C11 = A10*B01 + A11*B11

    mul( A, B, C, aii[0][0], bii[0][0], cii[0][0] );
    mul( A, B, C, aii[0][1], bii[1][0], cii[0][0] );

    mul( A, B, C, aii[0][0], bii[0][1], cii[0][1] );
    mul( A, B, C, aii[0][1], bii[1][1], cii[0][1] );

    mul( A, B, C, aii[1][0], bii[0][0], cii[1][0] );
    mul( A, B, C, aii[1][1], bii[1][0], cii[1][0] );

    mul( A, B, C, aii[1][0], bii[0][1], cii[1][1] );
    mul( A, B, C, aii[1][1], bii[1][1], cii[1][1] );
}