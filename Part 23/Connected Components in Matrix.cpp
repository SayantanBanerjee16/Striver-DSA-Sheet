// PROBLEM :- https://leetcode.com/problems/number-of-islands/

// LEETCODE | MEDIUM | GRAPHS CONNECTED COMPONENTS OVER MATRIX

// Solution :- T.C. O(N * M) S.C. O(1)

// Iterate over the matrix, whenever we encounter a '1', increment the "connected component" counter,
// and have a DFS marking all of the neighbouring components from '1' to '0'.

class Solution {
public:
    
    void dfs(int i, int j, int N, int M, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= N || j >= M || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        dfs(i - 1, j, N, M, grid);
        dfs(i + 1, j, N, M, grid);
        dfs(i, j - 1, N, M, grid);
        dfs(i, j + 1, N, M, grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        
        int connected_components = 0;
        
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(grid[i][j] == '1'){
                    connected_components++;
                    dfs(i, j, N, M, grid);
                }
            }
        }
        
        return connected_components;
    }
};