// PROBLEM :- https://leetcode.com/problems/edit-distance/

// LEETCODE | HARD | DP

// Solution :- T.C. O(N * M) S.C. O(N * M)

// If last characters of two strings are same, nothing much to do. 
// Ignore last characters and get count for remaining strings. 
// So just check minDistance(i - 1, j - 1)

// Else 3 other cases:-

// Insertion case (insert the last character of word2 in word1) :- 1 + minDistance(i, j - 1) 
// Deletion case (remove the last character of word1)           :- 1 + minDistance(i - 1, j)
// Replace case (replace the last character of word2 in word1)  :- 1 + minDistance(i - 1, j - 1)

// Form this solution recursively with memorization and then transform it into tabular method.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));
        
        for(int i=0 ; i < n + 1 ; i++)
            dp[i][0] = i;
        
        for(int j = 0 ; j < m + 1 ; j++)
            dp[0][j] = j;
        
        for(int i=1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        
        return dp[n][m];
    }
};