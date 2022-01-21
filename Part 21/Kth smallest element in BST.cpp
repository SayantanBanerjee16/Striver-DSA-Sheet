// PROBLEM :- https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// LEETCODE | MEDIUM | BST

// Solution :- T.C. O(K + H) S.C. O(1)

// We know that while doing an Inorder traversal, we process all the nodes in order.
// Thus do an inorder traversal, and exit after traversing through exactly K nodes.

class Solution {
public:
    
    void recurseInorder(TreeNode* node, int &ans, int &k){
        
        if(node == NULL)
            return;
        
        recurseInorder(node->left , ans, k);
        
        if(k == 0)
            return;
        
        k--;
        
        if(k == 0){
            ans = node->val;
            return;
        }
        
        recurseInorder(node->right , ans, k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        recurseInorder(root, ans , k);
        return ans;
    }
};