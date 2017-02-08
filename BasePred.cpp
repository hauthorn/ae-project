//
// This is the base class for the template method pattern
//
#include <vector>

using namespace std;

class BasePred {
protected:
    vector<int> array;
public:
    /**
     * This is the method you should override when to you pred
     * @param array
     * @param x
     * @return
     */
    virtual int pred(int x) = 0;

    /**
     * Sets the array to use by the Pred algorithm.
     *
     * @param array
     */
    void setArray(vector<int> array) {
        this->array = array;
    }
};