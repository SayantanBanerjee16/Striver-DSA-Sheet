// PROBLEM :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// LEETCODE | MEDIUM | RECURION, TREE

// Solution :- T.C. O(N) S.C. O(1)

// If root node is either P or Q, then we know root node is the LCA.

// Okay, so now we have 3 cases :-

// CASE 1 : If the left subtree recursive call gives a NULL value that means we haven’t found LCA in the left subtree, 
// which means we found LCA on the right subtree. So we will return right.

// CASE 2 : If the right subtree recursive call gives NULL value, that means we haven’t found LCA on the right subtree, 
// which means we found LCA on the left subtree. So we will return left.

// CASE 3 : If both left & right calls give tree node as values (not NULL)  that means the root is the LCA.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* LCAattainedFromLeftSubtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* LCAattainedFromRightSubtree = lowestCommonAncestor(root->right, p, q);
        
        if(LCAattainedFromLeftSubtree == NULL){
            return LCAattainedFromRightSubtree; // case 1
        }else if(LCAattainedFromRightSubtree == NULL){
            return LCAattainedFromLeftSubtree; // case 2
        }else{
            return root; // case 3
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */