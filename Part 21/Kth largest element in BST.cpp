// PROBLRM :- https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// GFG | EASY | BST

// Solution :- T.C. O(K + H) S.C. O(1)

// We know that while doing an Inorder traversal, we process all the nodes in order.
// Thus do an reverse inorder traversal, and exit after traversing through exactly K nodes.

class Solution
{
    
    void recurseInorder(Node* node, int &k, int &ans){
        
        if(node == NULL)
            return;
        
        recurseInorder(node->right , k, ans);
        
        if(k == 0)
            return;
        
        k--;
        
        if(k == 0){
            ans = node->data;
            return;
        }
        
        recurseInorder(node->left , k, ans);
        
    }
    
    
    public:
    int kthLargest(Node *root, int K)
    {
        int ans = -1;
        recurseInorder(root, K, ans);
        return ans;
    }
};