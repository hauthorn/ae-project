//
// Created by hauthorn on 3/4/17.
//

#include "BasePred.cpp"


class BinaryTreePred : public BasePred {
    struct TNode {
        unsigned int key;
        struct TNode *left, *right, *parent;
    };

    TNode *root;

public:
    unsigned int pred(unsigned int x) {
        return treePredecessor(root, x)->key;
    }

    /**
     * Builds a pointer based tree structure based on the array
     * @param array
     */
    void setArray(vector<unsigned int> array){
        // Grab the middle node
        
        // Insert the lower half
        
        // Insert the top half
        
        for (unsigned int i = 0; i < array.size(); i++){
            TNode *node = new TNode();
            node->key = array.at(i);
            insert(node);
        }
    }
    
    TNode* treePredecessor(TNode *node, unsigned int key) {
        if (node->key == key) {
            return node;
        }
        else if (node->key < key) {
            // Two cases, we either traverse down the tree, or we have our pred
            if (node->right) {
                return treePredecessor(node->right, key);
            }
            else {
                return node;
            }
        } else {
            // Two cases, we either traverse down the tree, or we didn't have a smaller number in the tree
            if (node->left) {
                return treePredecessor(node->left, key);
            }
            else {
                return node->parent;
            }
        }
    }

    /**
     * Insert a new node into the tree
     * @param node 
     */
    void insert(TNode *node) {
        TNode *y;
        TNode *x = root;
        
        while (x) {
            y = x;
            if (node->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        
        node->parent = y;
        
        if (!y) {
            root = node;
        }
        else if (node->key < y->key) {
            y->left = node;
        }
        else {
            y->right = node;
        }
    }
};