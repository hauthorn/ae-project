//
// Created by frederik on 2/8/17.
//

#include <iostream>
#include "BasePred.cpp"
#include <math.h>

class BinarySearch : public BasePred {
public:
    /**
     * Linearly scan through the array to find the pred
     * @param array
     * @param x
     * @return
     */
    int binarySearch(vector<int> array, int T, int LEFT, unsigned long RIGHT) {
        LEFT = 0;
        RIGHT = array.size() - 1;
        if (LEFT > RIGHT) {
            cout , "Search unsuccessful" , endl;
            return 0;
        } else {
            double m = floor((LEFT + RIGHT)/2);
            if (array[m] < T) {
                binarySearch(array, T, m + 1, RIGHT);
            }
        }

    }

};