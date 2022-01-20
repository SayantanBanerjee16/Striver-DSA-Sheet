// PROBLEM :- https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// LEETCODE | MEDIUM | TREE POINTERS

// Solution :- T.C. O(N) S.C. O(1)

// At each step, pass current node and its left and right.
// Its clear left->next = right.

// What about right->next = ???
// Taking examples we see that, right->next points to current_node->next->left.
// Connect it only if current_node->next doesn't points to NULL.

// Now similarly recursively do the connection for rest left subtree and right subtree nodes.


class Solution {
public:
    
    void recurse(Node* node, Node* left, Node* right){
        
        if(left == NULL || right == NULL){
            return;
        }
        
        
        left->next = right;
        
        if(node->next != NULL){
            right->next = node->next->left;
        }
        
        recurse(left, left->left, left->right);
        recurse(right, right->left, right->right);
        
    }
    
    
    Node* connect(Node* root) {
        
        if(root == NULL)
            return NULL;
        
        recurse(root, root->left, root->right);
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/