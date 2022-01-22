// PROBLEM :- https://leetcode.com/problems/binary-search-tree-iterator/

// LEETCODE | MEDIUM | BST ITERATOR

// Solution 1 :- T.C. O(1) S.C. O(N)

// Store all the nodes in inorder fashion in a vector.

// Solution 2:- T.C. O(1) average per operation S.C. O(H)

// Previous solution would be brute, but following similar idea, instead of storing all the nodes of inorder, store only the left deepest nodes in a stack.

// Upon calling next() -> we return from top of stack, and go to current node right, and again keep on storing all the left nodes.

// Upon calling hasNext() -> Just check if stack is empty or not. Return accordingly.


class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        pushAllLeftOfCurrent(root);
    }
    
    void pushAllLeftOfCurrent(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        pushAllLeftOfCurrent(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */