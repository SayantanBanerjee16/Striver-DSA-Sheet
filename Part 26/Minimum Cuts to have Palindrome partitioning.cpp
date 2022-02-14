// PROBLEM :- https://leetcode.com/problems/palindrome-partitioning-ii/

// LEETCODE | HARD | DP - MCM

// Solution :- T.C. O(N^2) S.C. O(N^2)

// Matrix Chain Multiplication variation as pseudo code by Aditya Verma.

class Solution {
public:
    
     bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<vector<int>> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
            
        return solve (s, 0, n-1, dp);
    }
};