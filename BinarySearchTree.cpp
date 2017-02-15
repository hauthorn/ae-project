//
// Created by frederik on 2/15/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "BasePred.cpp"

using namespace std;

struct TNode {
    int key;
    struct TNode *left, *right;
};

class BinarySearchTree : public BasePred {
private:
    int x;
    TNode* pred_root;

public:

    int pred(int x) {
        this->x = x;
        TNode* pred = findPre(this->pred_root, x);
        return pred->key;
    }

    void setArray(vector<int> array){
        int mid = array.size()/2;
        this->pred_root = newNode(array[mid]);

        for (int i = 1; i < array.size(); i++){
            pred_root = insert(pred_root, array[i]);
        }
        //this->pred_root = sortedArrayToBST(array, 0, (int)array.size()-1);
    }

    TNode* insert(TNode* node, int key){
        if (node == NULL) return newNode(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);
        return node;
    }

    // Helper function that allocates a new node with
    // given key and NULL left/right pointers

    struct TNode* newNode(int data) {

        TNode *temp = new TNode;
        temp->key = data;
        temp->left = temp->right = NULL;

        return temp;
    }

    TNode* findMax(TNode* root) {
        if (!root)
            return NULL;

        while (root->right) root = root->right;

        return root;
    }

    TNode* findPre(TNode* root, int key) {

        TNode *predecessor = NULL;
        TNode *current = root;

        // Base case
        if (root == NULL) {
            cout << "BINARYTREE:: root is NULL, returning." << endl;
            return 0;

        }
        while (current && current->key != key) {

            // If key is smaller than root key, go to left subtree
            if (current->key > key)
                current = current->left;
                // Else go to right subtree
            else {
                predecessor = current;
                current = current->right;
            }
        }
        if (current && current->left) {
            predecessor = findMax(current->left);
        }

        return predecessor;
    }
};