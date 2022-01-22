// PROBLEM :- https://leetcode.com/problems/flood-fill/

// LEETCODE | EASY | DFS

// Perform a DFS from the given position to all the 4 direction,
// when the current position cell value is equal to oldColor.
// Update color before performing DFS on neighbouring cells.


class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int N, int M, int &oldColor, int &newColor){
        if(i < 0 || j < 0 || i >= N || j >= M || image[i][j] != oldColor)
            return;
        
        image[i][j] = newColor;
        
        dfs(image, i - 1, j, N, M, oldColor, newColor);
        dfs(image, i + 1, j, N, M, oldColor, newColor);
        dfs(image, i, j - 1, N, M, oldColor, newColor);
        dfs(image, i, j + 1, N, M, oldColor, newColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int oldColor = image[sr][sc];
        
        if(oldColor == newColor)
            return image;
        
        int N = image.size();
        int M = image[0].size();
        
        dfs(image, sr, sc, N, M, oldColor, newColor);
        
        return image;
        
    }
};