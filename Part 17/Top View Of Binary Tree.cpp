// PROBLEM :- https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

// GFG | MEDIUM | TREE

// Solution :- T.C. O(N) S.C. O(N)

// What is a top view of tree? The tree nodes which can be visible when viewing from top.
// Which nodes can be visible from top? 
// The nodes which are at a certain X width from root, 
// and also no other nodes are at that width X from root in all the previous levels, ie.e, from 0 to depth Y.

// So to compute this, first attain the maximum width of the tree in both direction (left & right) using X co-ordinate.
// Build a Top-view vector corresponding to this total width.
// Now recurse based on X and Y co-ordinate, and if any node at certain width X, first check in the top-view vector if value is already present or not.
// If not present, store the node value with Y co-ordinate.
// If present, compare current Y co-ordinate with previously stored Y co-ordinate and replace if prev found Y co-ordinate is higher than current one.

// Note :- Deal carefully X co-ordinate value with vector addressing.

class Solution
{
    public:
    
    void recurseWidth(Node *node, int distX, int distY, int &widthLeft, int &widthRight){
        if(node == NULL)
            return;
            
        widthLeft = min(widthLeft, distX);
        widthRight = max(widthRight, distX);
        
        recurseWidth(node->left, distX - 1, distY + 1, widthLeft, widthRight);
        recurseWidth(node->right, distX + 1, distY + 1, widthLeft, widthRight);
    }
    
    void recurse(Node *node, int distX, int distY, vector<pair<int, int>> &topViewMap){
        if(node == NULL)
            return;
            
        int prevY = topViewMap[distX].second;
        if(distY < prevY){
            topViewMap[distX] = make_pair(node->data, distY);
        }
        
        recurse(node->left, distX - 1, distY + 1, topViewMap);
        recurse(node->right, distX + 1, distY + 1, topViewMap);
    }
    
    vector<int> topView(Node *root)
    {
        int widthRight = 0;
        int widthLeft = 0;
        recurseWidth(root, 0, 0, widthLeft, widthRight);
        int totalWidth = widthRight + 1 - widthLeft;
        
        vector<pair<int, int>> topViewMap(totalWidth, {INT_MAX, INT_MAX}); // X dist -> {value, Y dist}
        recurse(root, -widthLeft, 0, topViewMap);
        
        vector<int> topViewAns;
        for(auto itr : topViewMap){
            topViewAns.push_back(itr.first);
        }
        return topViewAns;
    }

};