// PROBLEM :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// LEETCODE | MEDIUM | TREE

// Solution :-

// We have Postorder and Inorder. We know in Postorder we visit LEFT then RIGHT then NODE.
// And in Inorder, we visit LEFT then NODE then RIGHT.

// So the current last node in POSTORDER array, will be the root node X, find the corresponding node in INORDER array.
// In the INORDER array, the nodes to the left of that node X, will be the nodes part of LEFT SUBTREE, 
// and the nodes to the right of node X, will be the nodes part of RIGHT SUBTREE. 

// So let say we have Y number of nodes to the right of inorder array to right of X. 
// Thus in the Postorder array, the previous Y elements from the last element will be the postorder traversal of those certain RIGHT SUBTREE nodes. 
// And the rest nodes of POSTORDER array, will be the preorder traversal of those certain LEFT SUBTREE nodes. 

// Solve them similarly recursively.

// For example

// inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// The last root node is 3. It is in 2nd position in inorder array.
// As there are 3 element to right of the root node in inorder array, so the no of nodes in RIGHT subtree will be 3.
//                                                                  and the no of nodes in LEFT subtree will be 1.
// So in postorder array, before the last root node, the prev 3 nodes would be preorder traversal for RIGHT subtree,
//                                        and the rest 1 node would be preorder traversal for LEFT subtree.
// Thus,
// root = 3
// root->left : postorder = [9], inorder = [9]
// root->right : postorder = [20,15,7], inorder = [15,20,7]

class Solution {
public:
    TreeNode* recurse(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &inorderPositions){
        
        if(postorderStart > postorderEnd){
            return NULL;
        }
        
        int val = postorder[postorderEnd];
        
        if(postorderStart == postorderEnd){
            return new TreeNode(val);
        }
        
        int index = inorderPositions[val];
        int leftTreeNodes = (index - inorderStart);
        int rightTreeNodes = (inorderEnd - index);
        
        TreeNode* node = new TreeNode(val);
        node->left = recurse(inorderStart, inorderStart + leftTreeNodes - 1, postorderStart, postorderStart + leftTreeNodes - 1, inorder, postorder, inorderPositions);
        node->right = recurse(inorderStart + leftTreeNodes + 1, inorderEnd , postorderStart + leftTreeNodes, postorderEnd - 1, inorder, postorder, inorderPositions);
        
        return node;
    }
        
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int N = inorder.size();
        
        unordered_map<int, int> inorderPositions;
        
        for(int i = 0 ; i < N ; i++){
            inorderPositions[inorder[i]] = i;
        }
        
        return recurse(0, N - 1, 0, N - 1, inorder, postorder, inorderPositions);
        
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