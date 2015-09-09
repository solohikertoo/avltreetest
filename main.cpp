#include <iostream>
#include "avl_tree.h"

using namespace std;

//demonstration of template class AVL Binary Search Tree
//enter symbols to insert into tree
// - updated balanced tree shown after each insert
//then enter symbols to remove from tree, updated balance tree shown
//- updated balanced tree shown after each remove

int main(int argc, char **argv)
{
    
    //here AvlTree and inputs of certain type are declared
    AvlTree<char> tree;
    char newKey;
    char terminate = '0';
    //AvlTree<int> tree;
    //int newKey;
    //int terminate = 0;
    
    //initialize flag for loop
    bool more = true;
    
    //loop to insert symbol and display tree, until
    //termination symbol entered
    do {
        cout << "enter symbol to insert, 0 to quit" << endl;
        cin >> newKey;
        cout << "-----------------" << endl;
        more = newKey != terminate;
        if (more) {
            //insert symbol
            tree.insert(newKey);
        }
        tree.displayTree();
        cout << "------------------" << endl;
    } while(more);
	
    //initialize flag for loop	
    more = true;
    
    //loop to remove symbol and display tree, until 
    //termination symbol entered
     do {
        cout << "enter symbol to remove, 0 to quit" << endl;
        cin >> newKey;
        cout << "-----------------" << endl;
        more = newKey != terminate;
        if (more) {
            //remove symbol
            tree.remove(newKey);
        }
        tree.displayTree();
        cout << "------------------" << endl;
    } while(more);    
    
	return 0;
}
