// PROBLEM :- https://leetcode.com/problems/search-in-a-binary-search-tree/

// LEETCODE | EASY | BST

// T.C. :- O(logN) S.C. O(1)

// Logic :- BST stores nodes in a systemic order. 
// Any lower value than current node is present in left side of that node, 
// and any greater value than the current node is present in right side of that node.

// So to search a particular node,
// if it is present then return that node, 
// or else travel towards only its left or right child based on comparison of the current node value and required value.

class Solution {
public:
    
    TreeNode* recurse(TreeNode* node, int val){
        
        if(node == NULL)
            return NULL;
        
        if(node->val == val){
            return node;
        }else if(node->val > val){
            return recurse(node->left, val);
        }else{
            return recurse(node->right, val);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return recurse(root, val);
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