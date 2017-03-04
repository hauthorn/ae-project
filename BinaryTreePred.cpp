//
// Created by hauthorn on 3/4/17.
//

#include <iostream>
#include "BasePred.cpp"
#include "RedBlackTree.cpp"

class BinaryTreePred : public BasePred {
    RedBlackTree *tree = new RedBlackTree;

public:
    unsigned int pred(unsigned int x) {
        return tree->pred(x);
    }

    /**
     * Builds a pointer based tree structure based on the array
     * @param array
     */
    void setArray(vector<unsigned int> array) {
        for (unsigned int i = 0; i < array.size(); i++) {
            tree->insert(array.at(i));
        }
    }
};