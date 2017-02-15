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
        return findPre(this->pred_root, this->pred_root, x);
    }

    void setArray(vector<int> array){
        this->pred_root = newNode(array[0]);

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
    /*
    struct TNode* sortedArrayToBST(vector<int> array, int start, int end){
        // Base case
        if (start > end)
            return NULL;

        // Make middle array element root
        int mid = (int)floor(start + end)/2;

        cout << "BINARY:: Setting root to " << array[mid] << endl;

        struct TNode* root = newNode(array[mid]);

        // Recursively construct left subtree and make it left child of root
        root->left = sortedArrayToBST(array, start, mid-1);

        // Recursively construct right subtree and make it right child of root
        root->right = sortedArrayToBST(array, mid+1, end);

        return root;
    }*/

    int findPre(TNode* root, TNode*& pre, int key){

        // Base case
        if (root == NULL) {
            cout << "BINARYTREE:: root is NULL, returning." << endl;
            return 0;

        }
        // If key is at root
        if (root->key == key) {

            // Max val in left subtree is pred
            if (root->left != NULL) {
                TNode* tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                pre = tmp;
            }
        }

        // If key is smaller than root key, go to left subtree
        if (root->key > key){
            pre = root;
            findPre(root->left, pre, key);
        }
        // Else go to right subtree
        else if (root->key < key){
            pre = root;
            findPre(root->right, pre, key);
        } else {
            cout << "BINARYTREE:: Pred found - " << pre->key << endl;
            return pre->key;
        }
    }
};