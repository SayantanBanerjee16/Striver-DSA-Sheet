// PROBLEM :- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

// LEETCODE | HARD | BST 

// Solution :- T.C. O(N) S.C. O(1)

// From any node, we return 3 things. {sum_of_subtree , min_node_of_subtree , max_node_of_subtree}
// Using the min node AND max node, we can tell if the current sub tree is a BST or not.
// If it is a BST, we update the ans to subtree_sum if it is found greater than previous stored sum.
// If it isn't a BST, all the ancestor nodes cannot form BST, so return {0, INT_MIN, INT_MAX} so that checker for BST fails at all its ancestor nodes.


class Solution {
public:
    
    vector<int> recurse(TreeNode* node, int &ans){
        
        int value = node->val;
        if(node->left == NULL && node->right == NULL){
            ans = max(ans, value);
            return {value , value , value};
        }else if(node->left != NULL && node->right != NULL){
            vector<int> leftChild = recurse(node->left , ans);
            vector<int> rightChild = recurse(node->right , ans);

            if(value > leftChild[2] && value < rightChild[1]){
                // BST as whole
                ans = max(ans , value + leftChild[0] + rightChild[0]);
                return { value + leftChild[0] + rightChild[0] , leftChild[1], rightChild[2] };
            }else{
                // no BST
                return {0 , INT_MIN , INT_MAX};
            }
            
        }else if(node->left != NULL){
            
            vector<int> leftChild = recurse(node->left , ans);
            if(value > leftChild[2]){
                // BST with left sub tree
                ans = max(ans, value + leftChild[0]);
                return { value + leftChild[0] , leftChild[0] , value};
            }else{
                // no BST
                return {0 , INT_MIN , INT_MAX};
            }
        }else{

            vector<int> rightChild = recurse(node->right , ans);
            if(value < rightChild[1]){
                // BST with right sub tree
                ans = max(ans, value + rightChild[0]);
                return { value + rightChild[0] , value , rightChild[1]};
            }else{
                // no BST
                return {0 , INT_MIN , INT_MAX};
            }
            
        }
        
    }
    
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        recurse(root, ans);
        return ans;
    }
};