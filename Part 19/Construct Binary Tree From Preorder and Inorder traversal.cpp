// PROBLEM :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// LEETCODE | MEDIUM | TREE

// Solution :-

// We have Preorder and Inorder. We know in Preorder we visit NODE then LEFT then RIGHT.
// And in Inorder, we visit LEFT then NODE then RIGHT.

// So the current first node in PREORDER array, will be the root node X, find the corresponding node in INORDER array.
// In the INORDER array, the nodes to the left of that node X, will be the nodes part of LEFT SUBTREE, 
// and the nodes to the right of node X, will be the nodes part of RIGHT SUBTREE. 

// So let say we have Y number of nodes to the left of inorder array to left of X. 
// Thus in the PREORDER array, the next Y elements from the first element will be the preorder traversal of those certain LEFT SUBTREE nodes. 
// And the rest nodes of PREORDER array, will be the preorder traversal of those certain RIGHT SUBTREE nodes. 

// Solve them similarly recursively.

// For example

// preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// The root node is 3. It is in 2nd position in inorder array.
// As their are 1 element to left of the root node in inorder array, so the no of nodes in left subtree will be 1.
//                                                                  and the no of nodes in right subtree wil be 3.
// So in preorder array, after the root node, the next 1 nodes would be preorder traversal for left subtree,
//                                        and the next 3 nodes would be preorder traversal for right subtree.
// Thus,
// root = 3
// root->left : preorder = [9], inorder = [9]
// root->right : preorder = [20,15,7], inorder = [15,20,7]


class Solution {
public:
    TreeNode* recurse(int inorderStart, int inorderEnd, int preorderStart, int preorderEnd, vector<int>& inorder, vector<int>& preorder, map<int, int> &inorderPositions){
        
        if(preorderStart > preorderEnd){
            return NULL;
        }
        
        int val = preorder[preorderStart];
        
        if(preorderStart == preorderEnd){
            return new TreeNode(val);
        }
        
        int index = inorderPositions[val];
        int leftTreeNodes = (index - inorderStart);
        int rightTreeNodes = (inorderEnd - index);
        
        TreeNode* node = new TreeNode(val);
        node->left = recurse(inorderStart, inorderStart + leftTreeNodes - 1, preorderStart + 1, preorderStart + leftTreeNodes, inorder, preorder, inorderPositions);
        node->right = recurse(inorderStart + leftTreeNodes + 1, inorderEnd , preorderStart + leftTreeNodes + 1, preorderEnd, inorder, preorder, inorderPositions);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int N = inorder.size();
        
        map<int, int> inorderPositions;
        
        for(int i = 0 ; i < N ; i++){
            inorderPositions[inorder[i]] = i;
        }
        
        return recurse(0, N - 1, 0, N - 1, inorder, preorder, inorderPositions);
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