// PROBLEM :- https://leetcode.com/problems/binary-tree-preorder-traversal/

// LEETCODE | EASY | TREE

// Solution 1 :- T.C. O(N) Aux S.C. O(1) -> RECURSIVE
// Recurse each node. First insert the current node, then visit left Subtree, and then visir right Subtree.

class Solution {
public:
    
    void recurse(TreeNode* node, vector<int> &preorder) {
        if(node == NULL)
            return;
        
        preorder.push_back(node->val);
        recurse(node->left, preorder);
        recurse(node->right, preorder);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        recurse(root,preorder);
        return preorder;
    }
};

// Solution 2 :- T.C. O(N) Aux S.C. O(N) -> Mantain an Auxiliary Stack
// Push the root node in stack.

// REPEAT
//      At any current node, insert it into stack and go towards left. 
//      Also whenever we encounter a new node, add it to output stack.
//      If at any moment we reach NULL, then use the last inserted node in stack, pop it and go towards right.
//      BREAK when there are no more nodes left in stack to process.

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preorder;
        TreeNode* node = root;
        stack<TreeNode*> stk;
        
        while(true){
            if(node == NULL){
                if(stk.empty())
                    break;
                node = stk.top();
                stk.pop();
                node = node->right;
            }else{
                stk.push(node); 
                preorder.push_back(node->val);
                node = node->left; 
            }
        }
        
        return preorder;
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