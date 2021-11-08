// PROBLEM:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// LEETCODE | MEDIUM | DP

// T.C :- O(N) , S.C O(N)

// dp[i][own] -> max amount i acheive in dates [i..N - 1] and also am holding a stock in Ith day
// dp[i][!own] -> max amount i acheive in dates [i..N - 1] and also am NOT holding a stock in Ith day

// final ans -> dp[0][!own]

// dp[i][own] = max(dp[i+1][own], dp[i+1][!own] + prices[i] - fee) 
// {max(hold that stock, sell that stock on this day)}

// dp[i][!own] = max(dp[i+1][!own], dp[i+1][own] - prices[i]) 
// {max(hold nothing, buy that stock on this day)}

// DP[N][2] -> array size : In 2nd part buy/!own -> 0th ; sell/own -> 1st


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int N = prices.size();
        
        vector<vector<int>> dp(N, vector<int>(2, 0));
        
        dp[N - 1][1] = max(0, prices[N - 1] - fee);
        
        for(int i = N - 2 ; i >= 0 ; i--){
            dp[i][0] = max(dp[i+1][0], dp[i+1][1] - prices[i]);
            dp[i][1] = max(dp[i+1][1], dp[i+1][0] + prices[i] - fee);
        }
        
        return dp[0][0];
    }
};