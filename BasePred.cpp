//
// This is the base class for the template method pattern
//

#ifndef BASEPRED
#define BASEPRED

#include <vector>

using namespace std;

class BasePred {
protected:
    vector<unsigned int> *array;
public:
    /**
     * This is the method you should override when to you pred
     * @param array
     * @param x
     * @return
     */
    virtual unsigned int pred(unsigned int x) = 0;

    virtual /**
     * Sets the array to use by the Pred algorithm.
     *
     * @param array
     */
    void setArray(vector<unsigned int> *array) {
        this->array = array;
    }

    /**
     * This is used by verify
     * @param array
     */
    void setArray(unsigned int array[]) {
        this->array = new vector<unsigned int>(array, array + sizeof(array) / sizeof(array[0]));
    }
};

#endif