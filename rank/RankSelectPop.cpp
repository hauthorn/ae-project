//
// Created by anders on 3/9/17.
//
#include <vector>
#include <bitset>

using namespace std;

class RankSelectPop {
private:
    vector<unsigned long> r_s;
    vector<unsigned long> r_b;


    vector<bitset<8> > r_p;

public:

    const static int s = 32;
    const static int b = 8;

    RankSelectPop(vector<bool> *v) {

        this->r_s = vector<unsigned long>(v->size()/this->s);
        this->r_b = vector<unsigned long>(v->size()/this->b);
        unsigned long vS = 0;

        unsigned long vB;

        for(unsigned long j = 0; j < v->size()/this->s; j++) {
            this->r_s[j] = vS;
            vB = 0;
            for(unsigned long k = 0; k < v->size()/this->b; k++) {
                bitset<b> bitset1;

                for(int l = 0; l < b; l++) {
                    bitset1.set(l,  v->at(j*k+l));
                }

                this->r_p[k*j] = bitset1;

                vB += this->r_p[k*j].count();

            }

            vS+=vB;
        }
    }

    unsigned long rank(unsigned long i) {

        return this->r_s[i/this->s]+this->r_b[i/this->b];
    }
};
