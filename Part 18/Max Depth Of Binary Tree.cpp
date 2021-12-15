// PROBLEM :- https://leetcode.com/problems/maximum-depth-of-binary-tree/

// LEETCODE | EASY | TREE

// Solution :- T.C. O(N) S.C. O(1)

// Recursively at each node, return 1 plus the max of depth at left subtree OR depth at right subtree.

class Solution {
public:
    
    int recurse(TreeNode* node){
        if(node == NULL)
            return 0;
        return 1 + max(recurse(node->left) , recurse(node->right));
    }
    
    int maxDepth(TreeNode* root) {
        return recurse(root);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */