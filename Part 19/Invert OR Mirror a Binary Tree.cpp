// PROBLEM :- https://leetcode.com/problems/invert-binary-tree/

// LEETCODE | EASY | TREE

// Solution :- T.C. O(N) S.C. O(1)

// Lets think node wise. After inversion, the right sub tree content should be pointed to left side. 
// And similarly left subtree content should be pointed to right side.

// So first recurse on both left and right child, so that those nodes can be applied invertion recursively, and then 
// interchange pointers as described above.

class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* invertedLeft = invertTree(root->left);
        TreeNode* invertedRight = invertTree(root->right);
        root->left = invertedRight;
        root->right = invertedLeft;
        return root;
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