// PROBLEM :- https://leetcode.com/problems/diameter-of-binary-tree/

// LEETCODE | EASY | DP ON TREES

// Solution :- T.C. O(N) S.C. O(1)

// Intuition :- Any longest diameter chain will pass through a node which is the topmost node, 
// and rest of the chain lies in left and right subtree.

// Logic :- At any node, check for longestPart in left subtree and also in right subtree
//          Now store the current path = 1 + longest path in left + longest path in right.
//          Check this value with the stored longestDiameter value, update it if current is more.
//          What to return from current node? Only 1 chain from either left or right will sustain.
//          Return 1 + max(longest path in left, longest path in right).


int recurse(TreeNode* node, int &longestDiameter){
    if(node == NULL)
        return 0;
    
    int left = recurse(node->left, longestDiameter);
    int right = recurse(node->right, longestDiameter);
    
    int pathLeftOrRight = max(left, right) + 1;
    int pathLeftANDRight = 1 + left + right;
    longestDiameter = max(longestDiameter, pathLeftANDRight);
    
    return pathLeftOrRight;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int longestDiameter = 0;
        recurse(root, longestDiameter);
        return longestDiameter - 1; // as we stored total num of nodes in longestDiameter. The edges path value is 1 less than that.
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