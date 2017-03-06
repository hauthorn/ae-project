#include <iostream>
#include "RankSelectSpace.cpp"
#include "rankSelectNaive.cpp"
#include <ctime>
#include "papi.h"
using namespace std;

int main(int argc, char *argv[]) {
    int n = 10000;
    vector<bool> X;

        /**
         * build array
         */
        for(int i = 0; i < n; i++)
            X.push_back(rand()%2);

        RankSelectSpace *s = new RankSelectSpace(X);
        RankSelectNaive *naive = new RankSelectNaive(X);

        cout << "Array size: " << n << endl;

        for(int t = 0; t < 100; t++) {
            int position = rand() % n;
            cout << "s found: " << (s->rank(position)) << " and naive found " << naive->rank(position) << endl;
        }




    return 0;
}