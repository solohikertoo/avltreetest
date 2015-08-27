#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <sstream>
#include <cmath>

using namespace std;

//constants to display tree using text
const int DISPLAY_WIDTH = 71;
const int DISPLAY_HEIGHT = 15;
const int DISPLAY_CENT = 35;
const int CHAR_WIDTH = 5;

//2-d character array to hold text display of tree
char displayArr[DISPLAY_HEIGHT][DISPLAY_WIDTH];

//flag to turn off/on self balancing of tree - for testing
bool rotateFlag = true;


//AvlTree - self balancing Binary Search Tree
//with nodes containing keys of type T

//the class T must overload the < and > comparison operators and 
//the ostringstream << operator

template <class T>
class AvlTree 
{
public:
    //public methods on AvlTree
    AvlTree() : root(NULL) {};
    void insert(T newKey);
    void remove(T removeKey);
    void displayTree();
    
    
private:
    //a node of the tree, with:
    // key of type T
    // balance = height of right child - height of left child
    // pointers to left and right children
    struct AvlNode
    {
        T key;
        int balance;    
        AvlNode *left;
        AvlNode *right;
        
        //constructor takes a key, sets balance to 0 and pointers to NULL
        AvlNode(T newKey) :  key(newKey), balance(0),
                                left(NULL), right(NULL) {}
    };
    
    //the root node of the AvlTree
    AvlNode* root;
    
    //private recursive methods on AvlNode
    #include "avl_node_insert.h"   
    #include "avl_node_remove.h"
    #include "avl_node_rotate.h"
    #include "avl_node_placechar.h"
};

//public methods on AvlTree

//insert a key into the tree
template<class T> 
void AvlTree<T>::insert(T newKey) {
    insert(root,newKey);
}

//remove a key from the tree
template<class T> 
void AvlTree<T>::remove(T removeKey) {
    remove(root,removeKey);
}

//display the tree using simple text display
template<class T> 
void AvlTree<T>::displayTree() {
    
    int i,j;
    for (i=0; i<DISPLAY_HEIGHT; i++) 
        for (j=0; j<DISPLAY_WIDTH; j++)
            displayArr[i][j]=' ';
            
    if (root != NULL)        
        placeChar(root,0,DISPLAY_CENT,DISPLAY_CENT/2);    

    for (i=0; i<DISPLAY_HEIGHT; i++) {
        for (j=0; j<DISPLAY_WIDTH; j++) {
            cout << displayArr[i][j];
        }
        cout << endl;
    }
}


#endif