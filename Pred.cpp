#include <iostream>
#include <vector>

using namespace std;

class Pred {
public:
    /**
     * Linearly scan through the array to find the pred
     * @param array
     * @param x
     * @return
     */
    static int predWithScan(vector<int> array, int x) {
        int max = 1;

        int size = array.size();

        for (int i = 0; i < size; ++i) {
            if (array[i] > max && array[i] <=x) {
                max = array[i];
            }
        }

        return max;
    }
};