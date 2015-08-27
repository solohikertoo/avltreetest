#ifndef _AVL_NODE_ROTATE_
#define _AVL_NODE_ROTATE_


   //pointer manipulation to rotate tree to the right
    void rotateRight(AvlNode*& root) {
        AvlNode *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        root = temp;
    }

    //pointer manipulation to rotate tree to the left
    void rotateLeft(AvlNode*& root) {
        AvlNode *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        root = temp;
    }

#endif