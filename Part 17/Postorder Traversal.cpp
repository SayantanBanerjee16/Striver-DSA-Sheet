// PROBLEM :- https://leetcode.com/problems/binary-tree-postorder-traversal/

// LEETCODE | EASY | TREE

// Solution 1 :- T.C. O(N) Aux S.C. O(1) -> RECURSIVE
// Recurse each node. First visit left Subtree, and then visir right Subtree, and finally insert the current node.

class Solution {
public:
    
    void recurse(TreeNode* node, vector<int> &postorder) {
        if(node == NULL)
            return;
        
        recurse(node->left, postorder);
        recurse(node->right, postorder);
        postorder.push_back(node->val);
        
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        recurse(root,postorder);
        return postorder;
    }
};


// Solution 2 :- T.C. O(N) Aux S.C. O(N) -> Mantain an Auxiliary Stack
// Push the root node in stack.

// REPEAT
//      At any current node, insert it into stack, and also in reversePostorder vector and go towards right.
//      If at any moment we reach NULL, then use the last inserted node in stack, pop it and go towards left.

// By this way, we would be  attaining reverse postorder, to get postorder, reverse that attained vector.

class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> reversePostorder;
        TreeNode* node = root;
        stack<TreeNode*> stk;
        
        while(true){
            if(node == NULL){
                if(stk.empty())
                    break;
                node = stk.top();
                stk.pop();
                node = node->left;
            }else{
                stk.push(node); 
                reversePostorder.push_back(node->val);
                node = node->right; 
            }
        }
        
        vector<int> postorder = reversePostorder;
        reverse(postorder.begin(), postorder.end());
        
        return postorder;
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