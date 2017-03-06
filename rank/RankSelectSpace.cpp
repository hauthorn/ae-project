/**
 * rank select with an attempt to implement the classical solution described in: http://personales.dcc.uchile.cl/~gnavarro/ps/wea05.pdf
 */
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class RankSelectSpace {
private:
    vector<bool> v;
    vector<unsigned long> r_s;
    vector<int> r_b;
    unsigned long b;// block size
    unsigned long s;// superblock size

    /**
     * find which superblock a given block is positioned in
     * @return
     */
    double findS(int b) {
        return floor(b/this->s);
    }

    /**
     * calculate which block a given index is positioned in
     * @param i
     * @return
     */
    double findB(unsigned long i) {
        return floor(i / this->b);
    }

public:
    RankSelectSpace(vector<bool> v) {
        this->v = v;
        //this->b = floor(log2(v.size()));
        //this->s = this->b*floor(log2(v.size()));
        this->b = 5;
        this->s = 3;
        // superblock j (with size s)
        // block k (with size b)


        unsigned long c = 0;

        unsigned long index = 0;
        // outer loop is super block, first innerloop is block and the innermost loop is s
        for(unsigned long j = 0; j < (floor(v.size()/this->s)/this->b); j++) {
            // we want the rank up to the superblock in this
            this->r_s.push_back(c);

            int s2 = 0;

            // loop through all blocks in superblock
            for(int k = 0; k < this->s; k++) {
                // remember k = k*j
                this->r_b.push_back(s2);

                for(int i = 0; i < this->b; i++) {
                    if(this->v[index]) {
                        c++;
                        s2++;
                    }
                    index++;
                }
            }
        }
    }

    /**
     * calcualte rank for given index
     * @param i
     * @return
     */
    unsigned long rank(unsigned long i) {
        // calculate the remaining in the block
        int m = 0;
        for(unsigned long l = this->findB(i)*this->b; l < i; l++) {
            if(this->v[l])
                m++;
        }

        if(this->findS(this->findB(i)) == 0 && this->findB(i)==0)
            return m;

        return this->r_s[this->findS(this->findB(i))]+r_b[this->findB(i)]+m;
    }
};
