//
// Created by christoffer on 2/8/17.
//

#include <iostream>
#include "BasePred.cpp"


class LinearScanPred : public BasePred {
public:
    /**
     * Linearly scan through the array to find the pred.
     * The array doesn't have to be sorted for this to work.
     *
     * @param array
     * @param x
     * @return
     */
    unsigned int pred(unsigned int x) {
        unsigned int max = 0;

        unsigned long size = this->array.size();

        for (unsigned int i = 0; i < size; ++i) {
            if (this->array.at(i) > max && this->array.at(i) <= x) {
                max = this->array.at(i);
            }
        }

        return max;
    }

};