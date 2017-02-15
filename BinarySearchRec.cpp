//
// Created by frederik on 2/8/17.
//

#include <iostream>
#include <math.h>
#include "BasePred.cpp"

using namespace std;

class BinarySearchRec : public BasePred {
private:
    // x is the value we are looking for, p is the closest so far
    int x, p;

public:
    /**
     * Binary search through the array to find the pred
     * @param array
     * @param x
     * @return
     */
    int pred(int x) {
        this->x = x;
        return binarySearch(0, (this->array.size())-1);
    }

    int binarySearch(int l, int r) {
        if(l > r){
            // we are done, return the closest matching
            return this->p;
        }

        // position of the middle element
        int m = floor((l+r)/2);

        if(this->array[m] < x) {
            // save this as closest
            this->p = this->array[m];

            // look to the right
            return binarySearch(m+1, r);
        } else if(this->array[m] > x) {
            // look to the left
            return binarySearch(l, m-1);
        } else {
            // found actual value
            return x;
        }
    }

};