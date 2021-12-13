// PROBLEM :- https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// GFG | EASY | TREE

// Solution 1 :- T.C. O(N) S.C. O(N)
// Using level order BFS, take the leftmost node from each level.

// Solution 2 :- T.C. O(N) S.C. O(Height)
// First find the max height of tree.
// Build a vector of size Height, representing all the levels. Initialize with -1.
// Recurse in each sub tree, first left, then right.
// If at any level, it's value in array is -1, that means the current node is the leftmost of the current level. Store it.

int heightRecurse(Node *node){
    if(node == NULL)
        return 0;
    int leftHeight = heightRecurse(node->left);
    int rightHeight = heightRecurse(node->right);
    return 1 + max(leftHeight, rightHeight);
}

void recurseLeftView(Node *node, int curLevel, vector<int> &levelsLeftView){
    if(node == NULL)
        return;
    if(levelsLeftView[curLevel] == -1){
        levelsLeftView[curLevel] = node->data;
    }
    recurseLeftView(node->left, curLevel + 1, levelsLeftView);
    recurseLeftView(node->right, curLevel + 1, levelsLeftView);
    return;
}

vector<int> leftView(Node *root)
{
   if(root == NULL)
        return {};
   
   int height = heightRecurse(root);
   vector<int> levelsLeftView(height, -1);
   
   recurseLeftView(root, 0, levelsLeftView);
   
   return levelsLeftView;
   
}

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
