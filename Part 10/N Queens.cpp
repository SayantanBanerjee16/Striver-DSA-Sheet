// Solution :- https://leetcode.com/problems/n-queens/

// LEETCODE | HARD | BACKTRACKING

// Solution 1 :- T.C. O(N!) and Amortized S.C O(1)

// Place queens on every position of each rows and recursively check for valid combinations for the next rows until last.
// How to check if a queen can be placed in a position?
// Linearly check the column, main diagonal and the anti diagonal. (only check the filled up upward section, as downward section is yet to be filled, so no queens there.)

class Solution {
public:
    
    bool isValid(int row, int col, int n, vector<string> &grid){
        for(int i = row - 1 ; i >= 0 ; i--){
            if(grid[i][col] == 'Q'){
                return false;
            }
        }
        
        int i = row - 1;
        int j = col - 1;
        
        while(i >= 0 && j >= 0){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        i = row - 1;
        j = col + 1;
        
        while(i >= 0 && j < n){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        
        return true;
    }
    
    void recurse(int row, int n, vector<string> &grid, vector<vector<string>> &output){
        
        if(row == n){
            output.push_back(grid);
            return;
        }
        
        for(int col = 0 ; col < n ; col++){
            
            if(isValid(row, col, n, grid)){
                grid[row][col] = 'Q';
                recurse(row + 1, n, grid, output);
                grid[row][col] = '.';
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string cur = "";
        for(int i = 0 ; i < n ; i++){
            cur += '.';
        }
        
        vector<string> grid;
        for(int i = 0 ; i < n ; i++){
            grid.push_back(cur);
        }
        
        vector<vector<string>> output;
        
        recurse(0, n, grid, output);
        
        return output;
        
    }
};

// Solution 2 :- T.C. O(N!) and Amortized S.C O(N) -> Better than Solution 1 becuase it saves time in computation whether a queen can be placed in a position or not in O(1)

// How?

// Whenever we place a queen, MARK its corresponding column, main diagonal and the anti diagonal.
// All position with same column, COL same.
//                   same main diagonal, ROW + COL same. (Range : 0 to 2 * N - 1)
//                   same anti diagonal, N - 1 + COL - ROW same. (Range : 0 to 2 * N - 1)


class Solution {
public:
    
    bool isValid(int row, int col, int n, vector<bool> &column, vector<bool> &antiDiagonal, vector<bool> &mainDiagonal)     {
        if(column[col] == true || antiDiagonal[n - 1 + col - row] == true || mainDiagonal[row + col] == true){
            return false;
        }else{
            return true;
        }
    }
    
    void recurse(int row, int n, vector<string> &grid, vector<vector<string>> &output, vector<bool> &column, vector<bool> &antiDiagonal, vector<bool> &mainDiagonal){
        
        if(row == n){
            output.push_back(grid);
            return;
        }
        
        for(int col = 0 ; col < n ; col++){
            
            if(isValid(row, col, n, column, antiDiagonal, mainDiagonal)){
                column[col] = true;
                antiDiagonal[n - 1 + col - row] = true;
                mainDiagonal[row + col] = true;
                grid[row][col] = 'Q';
                
                recurse(row + 1, n, grid, output, column, antiDiagonal, mainDiagonal);
                
                column[col] = false;
                antiDiagonal[n - 1 + col - row] = false;
                mainDiagonal[row + col] = false;
                grid[row][col] = '.';
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string cur = "";
        for(int i = 0 ; i < n ; i++){
            cur += '.';
        }
        
        vector<bool> column(n, false);
        vector<bool> mainDiagonal(2*n - 1, false);
        vector<bool> antiDiagonal(2*n - 1, false);
        
        vector<string> grid;
        for(int i = 0 ; i < n ; i++){
            grid.push_back(cur);
        }
        
        vector<vector<string>> output;
        
        recurse(0, n, grid, output, column, antiDiagonal, mainDiagonal);
        
        return output;
        
    }
};