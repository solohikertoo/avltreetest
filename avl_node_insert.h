#ifndef _AVL_NODE_INSERT_
#define _AVL_NODE_INSERT_
  
    //recursively insert a new key into the tree
    //return true if the magnitude of balance of node has increased
    
    bool insert(AvlNode*& tree, T newKey) {
        bool increased;
        int oldbalance;
    
        if (tree == NULL) {
            //at leaf, add node
            tree = new AvlNode(newKey);
            return true;
            
        } else if (newKey < tree->key) {
            //insert in left subtree
            
            oldbalance = tree->balance;
            increased = insert(tree->left, newKey);
            
            //if added to left subtree, balance changes 
            if (increased) 
                tree->balance--;  
             
            //compare magnitude of old and new balance to set 
            //increased flag to return
            increased = abs(oldbalance) < abs(tree->balance);
        
            //if balance made too negative, apply re-balancing
            if (rotateFlag && (tree->balance <-1)) {
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
                    
                } else {
                    //left-left case
                    rotateRight(tree);
                    tree->balance = 0;
                    tree->right->balance = 0;
                }
                
                //after balancing, set increased to false 
                increased = false;
            }
            
            return increased;
            
        } else if (newKey > tree->key) {
             //insert in right subtree
             
            oldbalance = tree->balance;
            increased = insert(tree->right, newKey);
            
             //if added to right subtree, balance changes 
            if (increased) 
                tree->balance++;
                
            //compare magnitude of old and new balance to set 
            //increased flag to return    
            increased = abs(oldbalance) < abs(tree->balance);
    
            //if balance made too large, apply re-balancing
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
                    tree ->left->balance = newLeftBal;
                    tree->right->balance = newRightBal;
                } else {
                    
                    //right-right case
                    rotateLeft(tree);
                    tree->balance = 0;
                    tree->left->balance = 0;
                }
                
                //after balancing, set increased to false 
                increased = false;
            }
            
            return increased;
            
        } else {
           // key already exists
           return false;
        } 
    }
    
#endif