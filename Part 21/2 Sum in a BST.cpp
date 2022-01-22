// PROBLEM :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// LEETCODE | EASY | BST , MAP

// Solution :- T.C. O(N) S.C. O(N)

// Do an inorder traversal.
// Mantain a set which stores all the number.
// Check if the number to find (target - node->val) is present in the set.
// If yes, return true.

// If in the end, after the whole traversal, target is not found, return false.


class Solution {
public:
    
    void recurse(TreeNode* node, int target, bool &found, unordered_set<int> &nums){
        
        if(found)
            return;
        
        if(node == NULL)
            return;
        
        recurse(node->left, target, found, nums);
        
        int leftOver = target - node->val;
        if(nums.count(leftOver) == 1){
            found = true;
            return;
        }
        
        nums.insert(node->val);
        
        recurse(node->right, target, found, nums);
        
    }
    
    
    bool findTarget(TreeNode* root, int target) {
        bool found = false;
        unordered_set<int> nums;
        recurse(root, target, found, nums);
        return found;
    }
};

// Solution 2 :- T.C. O(N) S.C. O(H)

// USING BST Iterator. Define one forward iterator and another backward iterator. 
// Then perform 2-sum search over sorted array solution.         

class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};
    bool hasNext() {
        return node != nullptr || !s.empty();
    }
    int next() {
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = s.top();
                s.pop();
                int nextVal = node->val;
                node = forward ? node->right : node->left;
                return nextVal;
            }
        }

        return -1;  // never reach & not necessary
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        for (int i = l.next(), j = r.next(); i < j;) {
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};