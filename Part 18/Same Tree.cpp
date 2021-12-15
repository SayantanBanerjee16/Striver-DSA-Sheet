// PROBLEM :- https://leetcode.com/problems/same-tree/

// LEETCODE | EASY | TREE

// Solution :- T.C. O(N) S.C. O(1)

// Solve recursively at each node. 
// If both nodes are NULL, both subtree DO match. 
// Else, If one node is NULL and other is NOT, both subtree don't match.
// Else, check the corresponding values of two nodes, and if they are same, recursively compare all these steps with both of their leftChild and both of their rightChild separately.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL && q != NULL)
            return false;
        else if(q == NULL && p != NULL)
            return false;
        else
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
