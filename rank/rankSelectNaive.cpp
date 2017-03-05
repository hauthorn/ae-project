//
// Created by anders on 3/5/17.
//
#include <bitset>
#include <vector>

using namespace std;

class RankSelectNaive {
private:
    vector<bool> v;
public:
    RankSelectNaive(vector<bool> v){
        this->v = v;
    }
    unsigned int rank(unsigned int i){
        int c = 0;

        for(int j = 0; j <= i; j++) {
            if(this->v.at(j))
                c++;
        }

        return c;
    }
    int select(int i);
};