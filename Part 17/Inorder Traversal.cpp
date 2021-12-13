// PROBLEM :- https://leetcode.com/problems/binary-tree-inorder-traversal/

// LEETCODE | EASY | TREE

// Solution 1 :- T.C. O(N) Aux S.C. O(1) -> RECURSIVE
// Recurse each node. First visit left Subtree, insert the current node, and then visir right Subtree.

class Solution {
public:
    
    void recurse(TreeNode* node, vector<int> &inorder) {
        if(node == NULL)
            return;
        
        recurse(node->left, inorder);
        inorder.push_back(node->val);
        recurse(node->right, inorder);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        recurse(root,inorder);
        return inorder;
    }
};

// Solution 2 :- T.C. O(N) Aux S.C. O(N) -> Mantain an Auxiliary Stack
// Push the root node in stack.

// REPEAT
//      At any current node, insert it into stack and go towards left.
//      If at any moment we reach NULL, then use the last inserted node in stack, pop it and go towards right.
//      BREAK when there are no more nodes left in stack to process.


class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        TreeNode* node = root;
        stack<TreeNode*> stk;
        
        while(true){
            if(node == NULL){
                if(stk.empty())
                    break;
                node = stk.top();
                stk.pop();
                inorder.push_back(node->val);
                node = node->right;
            }else{
                 stk.push(node); 
                 node = node->left; 
            }
        }
        
        return inorder;
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