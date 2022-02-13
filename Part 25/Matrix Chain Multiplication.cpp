// PROBLEM :- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// GFG | HARD | DP - MCM

// Solution :- T.C. O(N^3) S.C. O(N^2)

// Aditya Verma notes for in-depth explanation.

class Solution{
public:

    int solve(int arr[], int i, int j, vector<vector<int>> &dp){
        
        if(i >= j)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int mn = INT_MAX;
        for(int k = i ; k <= j - 1 ; k++){
            int tempAns = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            mn = min(mn, tempAns);
        }
        
        return dp[i][j] = mn;

    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(100, vector<int>(100, -1));
        return solve(arr, 1, N - 1, dp);
    }
};