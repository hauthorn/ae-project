//
// Created by frederik on 2/8/17.
//

#include <iostream>
#include <math.h>
#include "BasePred.cpp"

using namespace std;

class BinarySearch : public BasePred {
public:
    /**
     * Linearly scan through the array to find the pred
     * @param array
     * @param x
     * @return
     */
    int pred(int x) {
        binarySearch(x, 0, this->array.size()-1);

        return 0;
    }

    int binarySearch(int T, int LEFT, unsigned long RIGHT) {

        RIGHT = this->array.size() - 1;
        if (LEFT > RIGHT) {
            cout << "Search unsuccessful" << endl;
            return 0;
        } else {
            double m = floor((LEFT + RIGHT)/2);
            if (this->array[m] < T) {
                binarySearch(T, m + 1, RIGHT);
            }
        }
        return 0;
    }

};