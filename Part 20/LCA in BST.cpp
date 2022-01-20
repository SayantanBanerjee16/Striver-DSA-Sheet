// PROBLEM :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// LEETCODE | EASY | BST - LCA

// Solution :- T.C. O(N) S.C. O(1)

// If current node is either P or Q, then LCA is current node.
// Without loss of generality, let us assume P is smaller value node and Q is greater value node.
// If current node value is between P and Q, then current node is LCA.
// If both nodes value are less than current node value, then LCA should be to left subtree.
//                     are more                        , then LCA should be to right subtree.


class Solution {
public:
    
    TreeNode* recurse(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node->val == p->val || node->val == q->val || (node->val > p->val && node->val < q->val)){
            return node;
        }else if(node->val > p->val && node->val > q->val){
            return recurse(node->left, p, q);
        }else{
            return recurse(node->right, p, q);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val < q->val)
            return recurse(root, p, q);
        else
            return recurse(root, q, p);
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