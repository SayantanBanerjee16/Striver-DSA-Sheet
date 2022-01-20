// PROBLEM :- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// LEETCODE | MEDIUM | BST CONSTRUCTION FROM PREORDER

// Solution 1 : T.C. O(NlogN) S.C. O(N) Aux S.C. O(1)

// When we have the array range [Start ... End],
// we know the current node will be Array[Start].

// All values smaller than current node will be to the left of the start node,
// and all values greater than current node will be to the right of the end node.

// So for every range, find that MID value from where the range can be split into two halves,
// and solve each half recursively.

class Solution {
public:
    TreeNode* recurse(vector<int>& preorder, int start, int end) {
        
        if(start > end){
            return NULL;
        }
        
        if(start == end){
            TreeNode* node = new TreeNode(preorder[start]);
            return node;
        }
        
        TreeNode* node = new TreeNode(preorder[start]);
        
        int mid = -1;
        
        for(int i = start + 1 ; i <= end ; i++){
            if(preorder[i] > preorder[start]){
                mid = i;
                break;
            }
        }
        
        if(mid == -1){
            node->left = recurse(preorder, start + 1, end);
        }else{
            node->left = recurse(preorder, start + 1, mid - 1);
            node->right = recurse(preorder, mid, end);
        }
    
        return node;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return recurse(preorder, 0, preorder.size() - 1);
        
    }
};

// Solution 2 : T.C. O(N) S.C. O(N) Auc S.C. O(1)

// In this solution, we actually process each node value from preorder array in the given order.
// We process, and attach the node to their applicable region.

// For this, we use a UPPER BOUND of node values.
// Every node processed should be less than the UPPER BOUND.If not, we return NULL.

// Let's say the current node is in the bound, we create a node,
// And then in left subtree, we update the bound value to current node value.
// And then in right subtree, the bound value is same as current node bound value.

class Solution {
public:
    TreeNode* builtTree(vector<int>& preorder, int &index, int upper_bound) {
        
        int N = preorder.size();
        
        if(index == N || preorder[index] > upper_bound)
            return NULL;
        
        TreeNode *node = new TreeNode(preorder[index++]);
        node->left = builtTree(preorder, index, node->val);
        node->right = builtTree(preorder, index, upper_bound);
        
        return node;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index = 0;
        int upper_bound = INT_MAX;
        return builtTree(preorder, index, upper_bound);
        
    }
};