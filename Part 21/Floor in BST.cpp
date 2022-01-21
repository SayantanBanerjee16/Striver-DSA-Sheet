// PROBLEM :- https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

// CODE STUDIO | MEDIUM | BST

// Solution :- T.C. O(N) S.C. O(1)

// Recurse in the tree.
// If node value is equal to X, store it as ans, and dont recurse any more.
// If node value is less than X, store it as ans, and recurse on right subtree for even more better ans.
// If node value is more than X, recurse on left subtree for answer.

void recurse(TreeNode<int> * node, int &ans, int X){
    
    if(node == NULL)
        return;
    
    if(node->val == X){
        ans = X;
    }else if(node->val < X){
        ans = node->val;
        recurse(node->right , ans, X);
    }else{
        recurse(node->left , ans, X);
    }
    
}

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = INT_MIN;
    recurse(root , ans , X);
    return ans;
}