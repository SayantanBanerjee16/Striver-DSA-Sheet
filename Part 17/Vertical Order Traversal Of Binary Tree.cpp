// PROBLEM :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// LEETCODE | HARD | TREE, MAP

// Solution :- T.C. O(NlogN) S.C. O(N)

// Traverse the tree based on width X and depth Y co-ordinate.
// For all nodes with same width, push it in the map vector storing the Node value and Y co-ordinate.

// Later sort each map vector separately. 
// Sort it in such a way that, if two Y co-ordinate are same, sort based on node value. Else sort based on Y co-ordinate in ascending order.

map<int, vector<pair<int,int>>> mp;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    if(a.second == b.second)
        return a.first < b.first;
    return (a.second > b.second); 
} 

void calculate(TreeNode* node, int positionX, int positionY){
    
    if(node == NULL){
        return;
    }
    mp[positionX].push_back( make_pair(node->val, positionY));
    
    calculate(node->left, positionX - 1, positionY - 1 );
    calculate(node->right, positionX + 1, positionY - 1);
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp.clear();
        vector<vector<int> > output;
        if(root != NULL){
            calculate(root, 0, 0);   
        }
        for (auto i : mp){
            sort(i.second.begin(), i.second.end(), sortbysec);
            vector<int> temp;
            for (int j=0; j<i.second.size(); j++) 
            { 
                temp.push_back(i.second[j].first);
            } 
            output.push_back(temp);
        }
        return output;
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