// PROBLEM :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// LEETCODE | EASY | BST

// Solution :- T.C. O(N) S.C. O(N)

// If we have a sorted array, and we need to make a Balanced BST out of it.
// We can have the MID value of the current range as the current root,
// and all values to the left of MID, will be values to the left of the current root,
// and all values to the right of MID, will be values to the right of the current root.

// Recursively solve the left and right side.


class Solution {
public:
    
    TreeNode* recurse(vector<int>& nums, int low, int high){
        
        if(low > high)
            return NULL;
        
        int mid = low + ((high - low)/2);
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = recurse(nums, low, mid - 1);
        node->right = recurse(nums, mid + 1, high);
        
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1);
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