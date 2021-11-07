// PROBLEM :-
// https://leetcode.com/problems/unique-paths-ii/

// LEETCODE | MEDIUM | MATRIX DP

// Solution 1 :- Use recursion at each step.

// Solution 2 :- T.C. O(NM) S.C. O(NM)
//      No of paths leading to (i, j) = paths from (i - 1, j) + paths from (i, j - 1).
//      Use DP to memorize the current values.
//      If anywhere between, obstacles are added. Mark that position paths = 0.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};