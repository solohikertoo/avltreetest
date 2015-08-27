#ifndef _AVL_NODE_PLACECHAR_
#define _AVL_NODE_PLACECHAR_

// place character representing key/balance in 2-d character array
// for text display of tree
// - place character at input row and column in output character array
// - then recursively call for left and right children, increasing the 
//   row and decreasing/increasing the column by the offset for the 
//   left/right child

   void placeChar(AvlNode* tree, int row, int col,int offset) {
        if (row >=0 && row < DISPLAY_HEIGHT  &&
            col >=0 && col < DISPLAY_WIDTH &&
            tree != NULL) {
                
                //use string stream to convert symbol and balance
                //to character array called fill
                ostringstream out;
                out << tree->key <<"/"<<tree->balance;
                string fill = out.str();
                
                //set entries in 2-d character array for display
                for (int i = 0; i<(int)fill.size(); i++)
                    displayArr[row][col+i-CHAR_WIDTH/2]=fill[i];
        
            placeChar(tree->left, row+2,col-offset,offset/2);
            placeChar(tree->right,row+2,col+offset,offset/2);
        }
    }

#endif