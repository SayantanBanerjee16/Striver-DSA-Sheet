// PROBLEM :- https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#

// GFG | MEDIUM | BST

// Solution :- T.C. O(N) S.C. O(1)

/*  
    1. If root is NULL
           then return
    2. if key is found then
        a. If its left subtree is not null
            Then predecessor will be the right most 
            child of left subtree or left child itself.
        b. If its right subtree is not null
            The successor will be the left most child 
            of right subtree or right child itself.
        return
    3. If key is smaller then root node
            set the successor as root
            search recursively into left subtree
        else
            set the predecessor as root
            search recursively into right subtree 
            
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;

    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}