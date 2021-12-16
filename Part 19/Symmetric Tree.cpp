// PROBLEM :- https://leetcode.com/problems/symmetric-tree/

// LEETCODE | EASY | TREE

// Solution :- T.C. O(N) S.C. O(1)
// Exclude the root node, we will see we have two trees who are mirror of one another.
// Recursively check if the nodes are mirrored to one another.

class Solution {
public:
    
    bool isTwoTreeSymmetric(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }else if((p != NULL && q == NULL) || (p == NULL && q != NULL)){
            return false;
        }else{
            return (p->val == q->val) && (isTwoTreeSymmetric(p->left, q->right)) && (isTwoTreeSymmetric(p->right, q->left));
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        return isTwoTreeSymmetric(root->left, root->right);
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