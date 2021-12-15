// PROBLEM :- https://leetcode.com/problems/binary-tree-level-order-traversal/

// LEETCODE | MEDIUM | TREE

// Solution :- T.C. O(N) S.C. O(N)

// A classic BFS problem to attain level orders of binary tree.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        
        vector<vector<int>> levelOrderTraversal;
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()){
            int cur_size = bfs.size();
            vector<int> currentLevelOrder;
            for(int i = 0 ; i < cur_size ; i++){
                TreeNode* node = bfs.front();
                bfs.pop();
                currentLevelOrder.push_back(node->val);
                if(node->left != NULL){
                    bfs.push(node->left);
                }
                if(node->right != NULL){
                    bfs.push(node->right);
                }
            }
            levelOrderTraversal.push_back(currentLevelOrder);
        }
        
        return levelOrderTraversal;
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