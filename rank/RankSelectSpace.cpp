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

    double findIFromS(int s) {
        return this->b*this->s*s;
    }

    double findIFromB(int b) {
        return this->b*b;
    }

public:
    RankSelectSpace(vector<bool> v) {
        this->v = v;
        //this->b = floor(log2(v.size()));
        //this->s = this->b*floor(log2(v.size()));
        this->b = 128;
        this->s = 1024;
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

                // we want the rank up to this excluding current (first block is always zero)
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


        // prevent memory leak
        if(this->findS(this->findB(i)) == 0 && this->findB(i)==0)
            return m;

        return this->r_s[this->findS(this->findB(i))]+r_b[this->findB(i)]+m;
    }

    /**
     * binary search for the given value
     * @param i
     * @return
     */
    unsigned long select(unsigned long i) {
        unsigned long l=0, r=this->v.size()-1;

        while(l <= r) {
            int m = floor((l+r)/2);

            if(this->rank(m) < i) {
                l = m+1;
            } else if(this->rank(m) > i) {
                // look to the left
                r = m-1;
            } else {
                // found actual value
                return m;
            }
        }

        return 0;
    }

    unsigned long select2(unsigned long i) {

        // p is the closest block so far
        unsigned long pS = 0;

        unsigned long l = 0,r = this->r_s.size()-1;

        unsigned long m;

        // first binary search for the superblock
        while(l <= r) {
            m = floor((l+r)/2);

            if(this->r_s.at(m) < i) {
                // save this as closest
                if(m > pS)
                    pS = m;

                l = m+1;
            } else if(this->r_s.at(m) > i) {
                // look to the left
                r = m-1;
            } else {
                // found actual value
                pS = m;
                break;
            }
        }

        // l is where the superblock start, r is where it ends
        l = pS*this->s,
                r = pS*this->s+this->s-1;

        unsigned long pB = 0;

        // second binary search for the block
        while(l <= r) {
            m = floor((l+r)/2);

            unsigned long i2 = this->r_b.at(m) + this->r_s.at(pS);

            if(i2 < i) {
                // save this as closest
                if(m > pB)
                    pB = m-1;
                l = m+1;
            } else if(i2 > i) {
                // look to the left
                r = m-1;
            } else {
                // found the block where this happens (remember it is actually the block before)
                pB = m-1;
                break;
            }
        }

        unsigned long i2 = this->r_b.at(pB) + this->r_s.at(pS);

        pB=(pB)*this->b;

        // find remaining
        while(i2 < i) {
            if(this->v.size() == pB)
                return 0;
            if(this->v.at(pB))
                i2++;

            pB++;
        }


        return pB+1;
    }
};