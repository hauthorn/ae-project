//
// Created by hauthorn on 3/4/17.
//
struct TNode {
    unsigned int key;
    bool red = false; // false is black, true is red
    struct TNode *left, *right, *parent;
};

class RedBlackTree {
    TNode *root;
    TNode *nil;

public:
    RedBlackTree() {
        nil = new TNode();
        nil->red = false;
        root = nil;
    }

public:
    unsigned int pred(unsigned int x) {
        return predecessor(root, x)->key;
    }

    void insert(unsigned int key) {
        TNode *z = new TNode();
        z->parent = nil;
        z->key = key;

        TNode *y = nil;
        TNode *x = root;

        while (x != nil) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nil) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        z->left = nil;
        z->right = nil;
        z->red = true;

        insertFixup(z);
    }

    TNode *predecessor(TNode *node, unsigned int key) {
        if (node->key == key) {
            return node;
        } else if (node->key < key) {
            // Two cases, we either traverse down the tree, or we have our pred
            if (node->right && node->right != nil) {
                return predecessor(node->right, key);
            } else {
                return node;
            }
        } else {
            // Two cases, we either traverse down the tree, or we didn't have a smaller number in the tree
            if (node->left && node->left != nil) {
                return predecessor(node->left, key);
            } else {
                return node->parent;
            }
        }
    }

    /**
     * Preserve the red-black property of the tree
     * @param z
     */
    void insertFixup(TNode *z) {
        while (z->parent->red) {
            // The other side of the if statement is basically just a reverse of the following
            if (z->parent == z->parent->parent->left) {
                TNode *y = z->parent->parent->right;

                if (y && y->red) {
                    // CASE 1
                    z->parent->red = false;
                    y->red = false;
                    z->parent->parent->red = true;
                    z = z->parent->parent;
                } else if (z == z->parent->right) {
                    // CASE 2
                    z = z->parent;
                    leftRotate(z);
                }
                // CASE 3
                z->parent->red = false;
                z->parent->parent->red = true;
                rightRotate(z->parent->parent);

            } else {
                // Same as first clause, but with replaced left and right
                TNode *y = z->parent->parent->left;

                if (y && y->red) {
                    // CASE 1
                    z->parent->red = false;
                    y->red = false;
                    z->parent->parent->red = true;
                    z = z->parent->parent;
                } else if (z == z->parent->left) {
                    // CASE 2
                    z = z->parent;
                    rightRotate(z);
                }


                // CASE 3
                z->parent->red = false;

                if (z->parent->parent) {
                    z->parent->parent->red = true;
                    leftRotate(z->parent->parent);
                }
            }
        }
    }

    void leftRotate(TNode *x) {
        if (!x || x == nil) return;

        TNode *y = x->right;
        x->right = y->left; // turn y's left subtree into x's right subtree
        if (y->left != nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(TNode *x) {
        if (!x || x == nil) return;

        TNode *y = x->left;
        x->left = y->right; // turn y's right subtree into x's left subtree
        if (y->right != nil) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
};