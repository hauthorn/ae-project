//
// Created by hauthorn on 3/6/17.
//

#include <queue>
#include <iostream>
#include "BasePred.cpp"

class BinarySearchBFS : public BasePred {
public:
    unsigned int pred(unsigned int x) {
        unsigned long i = 0;
        unsigned int candidate = 0;

        while (i < this->array.size()) {
            unsigned int &comparison = this->array[i];
            if (x < comparison) {
                i = 2*i+1;
            }
            else if (x > comparison) {
                i = 2*i + 2;
                candidate = comparison;
            } else {
                return x;
            }
        }
        return candidate;
    }

    /**
     * Recursively build the BFS layout from the input array
     * @param array
     */
    void setArray(vector<unsigned int> array) {
        this->array = vector<unsigned int>();

        std::queue<pair<int, int>> queue;

        // Calculate the index-change for root
        unsigned int indexChange = (unsigned int) ((array.size() + 1) / 2 / 2);
        unsigned int index = (unsigned int) (array.size() / 2);

        // Insert root
        queue.push(make_pair(index, indexChange));

        bool last = false;

        while (!queue.empty()) {
            int i = queue.front().first;
            int change = queue.front().second;
            queue.pop();

            // Now to add the actual value to the array
            this->array.push_back(array[i]);

            if (last) {
                continue;
            }

            if (change == 0) {
                last = true;
            }

            if (i-change >= 0) {
                queue.push(make_pair(i-change, change / 2));
            }
            if (i+change < array.size()) {
                queue.push(make_pair(i+change, change / 2));
            }
        }

        this->array.shrink_to_fit();
    }
};