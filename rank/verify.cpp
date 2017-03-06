#include <iostream>
#include "RankSelectSpace.cpp"
#include "rankSelectNaive.cpp"
#include <ctime>
#include "papi.h"
using namespace std;

int main(int argc, char *argv[]) {
    int n = 1000000;
    vector<bool> X;

    /**
     * build array
     */
    for(int i = 0; i < n; i++)
        X.push_back(rand() % 2);

    RankSelectSpace *s = new RankSelectSpace(X);
    RankSelectNaive *naive = new RankSelectNaive(X);

    cout << "Array size: " << n << endl;

    for(int t = 0; t < 100; t++) {
        int j = rand()%1000;
        cout << "s found: " << (s->select(j)) << " and naive found " << naive->select(j) << endl;
    }

    return 0;
}