// PROBLEM :- https://leetcode.com/problems/binary-tree-maximum-path-sum/

// LEETCODE | HARD | DP ON TREE

// Solution :- T.C. O(N) S.C. O(1)

// At any node, the longest sum can be 
//      Either, node AND left path sum AND right path sum
//          OR, node AND MAX OF left path sum OR right path sum
//          OR, node only.

// Calculate each of those 3 cases.
// Update the answer variable, if any value is greater than previously stored value.
// Return only 1 path which is maximum. Thus return max of CASE 2 and CASE 3.

class Solution {
public:
    
    int recurse(TreeNode* node, int &maxPathSum){
        if(node == NULL)
            return 0;
        
        int leftPathMax = recurse(node->left, maxPathSum);
        int rightPathMax = recurse(node->right, maxPathSum);
        int curMax = node->val + max(0, max(leftPathMax, rightPathMax));
        maxPathSum = max(maxPathSum, curMax);
        maxPathSum = max(maxPathSum, leftPathMax + node->val + rightPathMax);
        return curMax;
    }
    
    
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        recurse(root, maxPathSum);
        return maxPathSum;
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