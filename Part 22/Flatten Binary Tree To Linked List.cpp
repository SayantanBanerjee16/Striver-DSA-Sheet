// PROBLEM :- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// LEETCODE | MEDIUM | TREE POINTER

// Solution 1:- T.C. O(N) S.C. O(1) -> RECURSIVE

// We will do a reverse preoder traversal. (RIGHT -> LEFT -> NODE)
// By virtue of which, all the nodes that are at left & right of NODE would already be in linked-list state.

// While executing the current node, we will connect current node right pointer to last node hold while traversal.
// And make its left pointer point to NULL.
// Now hold the current node as last node and REPEAT.

class Solution {
public:
    
    TreeNode* prev;
    
    void recurse(TreeNode *node){
        
        if(node == NULL)
            return;
        
        recurse(node->right);
        recurse(node->left);
        
        node->right = prev;
        node->left = NULL;
        prev = node;
        
    }
    
    
    void flatten(TreeNode* root) {
        prev = NULL;
        recurse(root);
    }
};