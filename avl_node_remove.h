#ifndef _AVL_NODE_REMOVE_
#define _AVL_NODE_REMOVE_

   //recursively search for input key and remove if found
   //return true if the magnitude of the balance has decreased
   bool remove(AvlNode*& tree, T removeKey) {
        bool decreased;
        int oldbalance;
        if (tree == NULL) {
            //at leaf and key not found
            return false;
            
        } else if (removeKey < tree->key) {
            //search left subtree
            oldbalance = tree->balance;
            decreased = remove(tree->left, removeKey);
            
            //if removed from left subtree, balance changes
            if (decreased)
                tree->balance++;
                
            //if balance too large, rebalance    
            if (rotateFlag && (tree->balance > 1)) {
                int newLeftBal, newRightBal;
                
                //right-left case
                if (tree->right->balance < 0) {
                
                    //balances for children after re-balancing
                    if (tree->right->left->balance < 0){
                        newLeftBal = 0;
                        newRightBal = 1;
                    } else if (tree->right->left->balance > 0) {
                        newLeftBal = -1;
                        newRightBal = 0;
                    } else {
                        newLeftBal = 0;
                        newRightBal = 0;
                    }
                  
                    rotateRight(tree->right);
                    rotateLeft(tree);
                    tree->balance = 0;
                    tree->left->balance = newLeftBal;
                    tree->right->balance = newRightBal;
                    
                } else if (tree->right->balance == 0) {
                    //right-balanced case
                    rotateLeft(tree);
                    tree->balance = -1;
                    tree->left->balance = 1;
                    
                } else {
                    //right-right case
                    rotateLeft(tree);
                    tree->balance = 0;
                    tree->left->balance = 0;
                }
         
            } 
            
            //compare magnitude of old and new balance to set 
            //decreased flag to return
            decreased = abs(oldbalance) > abs(tree->balance);
            return decreased;
            
        } else if (removeKey > tree->key) {
            //search right sub-tree
            oldbalance = tree->balance;
            decreased = remove(tree->right, removeKey);
            
            //if removed from right sub-tree, balance changes
            if (decreased)
                tree->balance--;
                
            //if balance too negative, re-balance    
            if (rotateFlag && (tree->balance < -1)) {
                int newLeftBal, newRightBal;
                
                //left-right case
                if (tree->left->balance >0 ) {
                    
                    //balances for children after re-balancing
                    if (tree->left->right->balance < 0){
                        newLeftBal = 0;
                        newRightBal = 1;
                    } else if (tree->left->right->balance > 0) {
                        newLeftBal = -1;
                        newRightBal = 0;
                    } else {
                        newLeftBal = 0;
                        newRightBal = 0;
                    } 
                
                    rotateLeft(tree->left);
                    rotateRight(tree);
                    tree->balance = 0;
                    tree->left->balance = newLeftBal;
                    tree->right->balance = newRightBal;
                    
                } else if (tree->left->balance == 0) {
                    //left-balanced case
                    rotateRight(tree);
                    tree->balance = 1;
                    tree->right->balance = -1;
                    
                } else {
                    //left-left case
                    rotateRight(tree);
                    tree->balance = 0;
                    tree->right->balance = 0;
                }          
            
            } 
            
            //compare magnitude of old and new balance to set 
            //decreased flag to return
            decreased = abs(oldbalance) > abs(tree->balance);
            return decreased;
            
        } else {
            //key found
            AvlNode* temp;
          
            if (tree->right == NULL) {
                //no right child, replace node with left child
                temp = tree;
                tree = tree->left;
                delete temp;
                decreased = true;   //balance changed
                
            } else if (tree->left == NULL) {
                //no left child, replace node with right child
                temp = tree;
                tree = tree->right;
                delete temp;
                decreased = true;  //balance changed
                
            } else {
                //node has both children, replace node with
                //largest key in left subtree
                AvlNode*& largest = findLargest(tree->left);
                char replaceKey = largest->key;
                tree->key = replaceKey;
                
                //recursivelyremove the node with largest key 
                //from the left subtree
                decreased = remove(tree->left,replaceKey);
                
                //if removed from left subtree, balance changes
                if (decreased)
                    tree->balance++;
            }
            
            return decreased;
        }
    }
 
    //recursively find node containing the largest key starting 
    //at input AvlNode
    //return reference to pointer to AvlNode containing key
    AvlNode*& findLargest(AvlNode*& tree) {
        if (tree->right == NULL) {
            return tree;    
        } else {
            return findLargest(tree->right);
        }
    }


#endif