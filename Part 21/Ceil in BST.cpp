// PROBLEM :- https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

// CODE STUDIO | MEDIUM | BST

// Solution :- T.C. O(N) S.C. O(1)

// Recurse in the tree.
// If node value is equal to X, store it as ans, and dont recurse any more.
// If node value is more than X, store it as ans, and recurse on left subtree for even more better ans.
// If node value is less than X, recurse on right subtree for answer.

// If finally ceil value not found, print -1.

void recurse(BinaryTreeNode<int> * node, int &ans, int X){
    
    if(node == NULL)
        return;
    
    if(node->data == X){
        ans = X;
    }else if(node->data > X){
        ans = node->data;
        recurse(node->left , ans, X);
    }else{
        recurse(node->right , ans, X);
    }
    
}

int findCeil(BinaryTreeNode<int> *root, int x){
    int ans = INT_MAX;
    recurse(root , ans , x);
    if(ans == INT_MAX)
        ans = -1;
    return ans;
}