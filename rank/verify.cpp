#include <iostream>
#include "RankSelectSpace.cpp"
#include "rankSelectNaive.cpp"
#include <ctime>
#include "papi.h"
using namespace std;

int main(int argc, char *argv[]) {
    int n = 1024*512;
    vector<bool> X(n);

    /**
     * build array
     */
    for(int i = 0; i < n; i++)
        X[i] = (rand() % 2);

    RankSelectSpace *s = new RankSelectSpace(X);
    RankSelectNaive *naive = new RankSelectNaive(X);

    cout << "Array size: " << n << endl;

    for(int t = 0; t < 100000; t++) {
        unsigned long j = floor(rand()%n/2);

        //cout << "select2 found: " << (s->select2(j)) << " and select found " << s->select(j) << " and naive found " << naive->select(j) << " for " << j << endl;
        unsigned long i = s->select2(j);
        unsigned long i1 = naive->select(j);
        if(i != i1) {
            cout << "Algo differs" <<  endl;
        }
    }

    return 0;
}