// PROBLEM :- https://leetcode.com/problems/rotting-oranges/

// LEETCODE | MEDIUM | MULTI SOURCE BFS

// Solution :- T.C. O(N * M) S.C. O(N * M)

// This is a typical multi source BFS problem. 
// Where expansion from all the current rotten oranges, and in the next iteration mark all the fresh orange as rotten. Include all these newly formed rotten oranges into the queue for the next overall iteration.

// In the end, find out the total number of overall iterations it took to completely mark all fresh oranges as rotten oranges.

// Return -1 if all the fresh oranges can't be marked as rotten oranges.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int freshOranges = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> rottenOranges;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }else if(grid[i][j] == 2){
                    rottenOranges.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        
        vector<int> dx{-1, 0, 1, 0};
        vector<int> dy{0, -1, 0, 1};
        
        while(freshOranges > 0 && rottenOranges.size() > 0){
            
            time++;
            
            int curSize = rottenOranges.size();
            
            while(curSize--){
                
                int x = rottenOranges.front().first;
                int y = rottenOranges.front().second;
                
                rottenOranges.pop();
                
                for(int i = 0 ; i < 4 ; i++){
                    int reqX = x + dx[i];
                    int reqY = y + dy[i];
                    
                    if(reqX < 0 || reqY < 0 || reqX >= n || reqY >= m || grid[reqX][reqY] == 0){
                        continue;
                    }
                    
                    freshOranges--;
                    rottenOranges.push({reqX, reqY});
                    grid[reqX][reqY] = 0;
                    
                }
                
                
            }
            
        }

        if(freshOranges == 0){
            return time;
        }else{
            return -1;
        }
        
    }
};