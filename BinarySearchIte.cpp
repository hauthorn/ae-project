//
// Created by frederik on 2/8/17.
//

#include <iostream>
#include <math.h>
#include "BasePred.cpp"

using namespace std;

class BinarySearchIte : public BasePred {
public:
    /**
     * Linearly scan through the array to find the pred
     * @param array
     * @param x
     * @return
     */
    unsigned int pred(unsigned int x) {
        unsigned int p = 0;

        unsigned int l = 0,
                r = this->array->size()-1;

        while(l <= r) {
            int m = floor((l+r)/2);

            if(this->array->at(m) < x) {
                // save this as closest
                p = this->array->at(m);
                l = m+1;
            } else if(this->array->at(m) > x) {
                // look to the left
                r = m-1;
            } else {
                // found actual value
                return x;
            }
        }

        // else return prede
        return p;
    }

};