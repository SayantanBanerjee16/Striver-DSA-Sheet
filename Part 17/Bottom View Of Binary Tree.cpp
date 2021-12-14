// PROBLEM :- https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

// GFG | MEDIUM | TREE

// Solution :- T.C. O(N) S.C. O(N)

// What is a bottom view of tree? The tree nodes which can be visible when viewing from bottom.
// Which nodes can be visible from bottom? 
// The nodes which are at a certain X width from root, 
// and also no other nodes are at that width X from root in all the futher levels, ie.e, from depth Y to depth D.

// So to compute this, first attain the maximum width of the tree in both direction (left & right) using X co-ordinate.
// Build a Top-view vector corresponding to this total width.
// Now recurse based on X and Y co-ordinate, and if any node at certain width X, first check in the top-view vector if something is present or not.
// If not present, store the node value with Y co-ordinate.
// If present, compare current Y co-ordinate with previously stored Y co-ordinate and replace if prev found Y co-ordinate is lower or equal than current one.

class Solution {
  public:
  
  void recurseWidth(Node *node, int distX, int distY, int &widthLeft, int &widthRight){
        if(node == NULL)
            return;
            
        widthLeft = min(widthLeft, distX);
        widthRight = max(widthRight, distX);
        
        recurseWidth(node->left, distX - 1, distY + 1, widthLeft, widthRight);
        recurseWidth(node->right, distX + 1, distY + 1, widthLeft, widthRight);
    }
    
    void recurse(Node *node, int distX, int distY, vector<pair<int, int>> &bottomViewMap){
        if(node == NULL)
            return;
            
        int prevY = bottomViewMap[distX].second;
        if(distY >= prevY){
            bottomViewMap[distX] = make_pair(node->data, distY);
        }
        
        recurse(node->left, distX - 1, distY + 1, bottomViewMap);
        recurse(node->right, distX + 1, distY + 1, bottomViewMap);
    }
    vector <int> bottomView(Node *root) {
        
        int widthRight = 0;
        int widthLeft = 0;
        recurseWidth(root, 0, 0, widthLeft, widthRight);
        int totalWidth = widthRight + 1 - widthLeft;
        
        vector<pair<int, int>> bottomViewMap(totalWidth, {INT_MIN, INT_MIN}); // X dist -> {value, Y dist}
        recurse(root, -widthLeft, 0, bottomViewMap);
        
        vector<int> bottomViewAns;
        for(auto itr : bottomViewMap){
            bottomViewAns.push_back(itr.first);
        }
        return bottomViewAns;
        
    }
};