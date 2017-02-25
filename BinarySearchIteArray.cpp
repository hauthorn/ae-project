//
// Created by frederik on 2/8/17.
//

#include <iostream>
#include <math.h>
#include "BasePred.cpp"

using namespace std;

class BinarySearchIteArray : public BasePred {
private:
    unsigned int *numbers;
    int n;
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
                r = n-1;

        while(l <= r) {
            int m = floor((l+r)/2);

            if(this->numbers[m] < x) {
                // save this as closest
                p = this->numbers[m];
                l = m+1;
            } else if(this->numbers[m] > x) {
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

    void setArray(vector<unsigned int> *array) {
        numbers = new unsigned int[array->size()];

        // convert to array (this is not measured by papi)
        for(int i = 0; i < array->size(); i++) {
            numbers[i] = array->at(i);
        }

        n = array->size();

    }

};