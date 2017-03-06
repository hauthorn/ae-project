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
    int rank(int i){
        int c = 0;

        for(int j = 0; j < i; j++) {
            if(this->v.at(j))
                c++;
        }

        return c;
    }

    int select(int i) {
        int c = 0;

        for(int j = 0; j < v.size(); j++) {
            if(this->v.at(j))
                c++;

            if(c == i)
                return j+1;
        }

        return 0;
    }
};