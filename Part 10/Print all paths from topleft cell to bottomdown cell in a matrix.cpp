// PROBLEM :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// GFG | MEDIUM | BACKTRACKING

// Solution :- T.C. O(3^N^2) S.C. O(L * X) L:- Length of path and X :- No of paths

// Visit from start cell, make a DFS recursion based on its adjacent cells.
// Before making a recursion call, mark that cell as blocked.
// After returing to that moment before recursion call, mark that cell as unblocked.

// Note :- We need to return the path in sorted manner. So visit Down (D), Left (L), Right (R), Up (U) in this order respectively.

class Solution{
    public:
    
    bool notValid(int x, int y, int n, vector<vector<int>> &mat){
        if(x < 0 || x >= n || y < 0 || y >= n || mat[x][y] == 0){
            return true;
        }
        return false;
    }
    
    void recurse(int x, int y, int n, vector<vector<int>> &mat, vector<string> &output, string &cur){
        
        if(notValid(x, y, n, mat)){
            return;
        }
        
        if(x == n - 1 && y == n - 1){
            output.push_back(cur);
            return;
        }
        
        mat[x][y] = 0;
        
        // down
        cur += 'D';
        recurse(x + 1, y, n, mat, output, cur);
        cur.pop_back();
        
        // left
        cur += 'L';
        recurse(x, y - 1, n, mat, output, cur);
        cur.pop_back();
        
        // right
        cur += 'R';
        recurse(x, y + 1, n, mat, output, cur);
        cur.pop_back();
        
        // up
        cur += 'U';
        recurse(x - 1, y, n, mat, output, cur);
        cur.pop_back();
        
        mat[x][y] = 1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        if(mat[0][0] == 0 || mat[n - 1][n - 1] == 0){
            return {"-1"};
        }
        vector<string> output;
        string cur = "";
        
        recurse(0, 0, n, mat, output, cur);
        
        if(output.size() == 0){
            return {"-1"};
        }
        
        return output;
    }
};