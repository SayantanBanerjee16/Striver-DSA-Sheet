// PROBLEM :- https://leetcode.com/problems/minimum-path-sum/

// LEETCODE | MEDIUM | DP on GRID

// Solution :- T.C. O(N * M) S.C. O(1) -> as done In-Place

// At every position, we can come from either its upside, or its leftside.
// So at every position, choose the minimum of the two, and add to the current value.
// Note that in first column, we can come from its leftside only. 
// Similarly in first row, we can come from upside only.

// Finally return grid[n - 1][m - 1] as answer.


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 1 ; i < n ; i++){
            grid[i][0] += grid[i - 1][0];
        }
        
        for(int j = 1 ; j < m ; j++){
            grid[0][j] += grid[0][j - 1];
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                grid[i][j] += min(grid[i - 1][j] , grid[i][j - 1]);
            }
        }
        
        return grid[n - 1][m - 1];
    }
};