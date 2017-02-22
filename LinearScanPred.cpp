//
// Created by christoffer on 2/8/17.
//

#include <iostream>
#include "BasePred.cpp"


class LinearScanPred : public BasePred {
public:
    /**
     * Linearly scan through the array to find the pred
     * @param array
     * @param x
     * @return
     */
    int pred(int x) {
        int max = 1;

        int size = (int) this->array->size();

        for (int i = 0; i < size; ++i) {
            if (this->array->at(i) > max && this->array->at(i) <= x) {
                max = this->array->at(i);
            }
        }

        return max;
    }

};