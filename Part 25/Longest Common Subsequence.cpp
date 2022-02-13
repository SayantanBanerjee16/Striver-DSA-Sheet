// PROBLEM :- https://leetcode.com/problems/longest-common-subsequence/

// LEETCODE | MEDIUM | DP

// Solution :- T.C. O(N * M) S.C. O(N * M)

// Recursively we see that if text1[i] == text2[j] , then find LCS of (i - 1 , j - 1) and add 1 to it.
// Else if they are not equal then, find maximum of either LCS of (i - 1 , j) or LCS of (i, j - 1).

// We actually find out LCS(N, M).

// Convert this logic into a Recursive + Memorization solution and later into a Tabular Solution.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));
        
        for(int i=1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};