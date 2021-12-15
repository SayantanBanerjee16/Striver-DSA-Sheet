// PROBLEM :- https://leetcode.com/problems/balanced-binary-tree/

// LEETCODE | EASY | TREE

// Solution :- T.C. O(N) S.C. O(1)
// At any node, check for max height in both left and right subtree.
// If the height difference is more than 1, return FALSE;


class Solution {
public:
    
    int recurse(TreeNode* node, bool &isBalancedTree){
        if(node == NULL || isBalancedTree == false)
            return 0;
        int leftSubtreeHeight = recurse(node->left, isBalancedTree);
        int rightSubtreeHeight = recurse(node->right, isBalancedTree);
        if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1){
            isBalancedTree = false;
        }
        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }
    
    
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;
        recurse(root, isBalancedTree);
        return isBalancedTree;
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