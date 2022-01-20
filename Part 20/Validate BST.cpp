// PROBLEM :- https://leetcode.com/problems/validate-binary-search-tree/

// LEETCODE | MEDIUM | BST CHECKER

// Solution :- T.C. O(N) S.C. O(1)

// We define a range [low --- high] and update this range while traversing to left or right sub tree, according to the values present in the nodes.
// Upon reaching a newer node, we check if its values is in between [low --- high], if it isn't, we return false.
// If current node values is okay, we check for left and right subtree after updating the range.

#define ll long long 
class Solution {
public:
    
    bool recurse(TreeNode* node, ll lower_bound, ll upper_bound){
        if(node == NULL)
            return true;
        
        if(node->val < lower_bound || node->val > upper_bound)
            return false;
        
        return recurse(node->left , lower_bound , node->val - 1LL) && recurse(node->right , node->val + 1LL , upper_bound);
    }
    
    bool isValidBST(TreeNode* root) {
        ll lower_bound = INT_MIN;
        ll upper_bound = INT_MAX;
        
        return recurse(root, lower_bound, upper_bound);
    }
};