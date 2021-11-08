// PROBLEM:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// LEETCODE | MEDIUM | DP

// T.C :- O(N) , S.C O(N)

// dp[i][own][x] -> max amount we can acheive in dates [i..N - 1] and also am holding a stock in Ith day
// dp[i][own][x] = max(dp[i + 1][own][x], dp[i + 1][!own][cool] + prices[i])
//                 max(hold it, sell it on current day)

// dp[i][!own][cool] -> max amount we can acheive in dates [i..N - 1] and also am NOT holding a stock in Ith day and also current day is cooldown
// dp[i][!own][cool] = dp[i + 1][!own][!cool]


// dp[i][!own][!cool] -> max amount we can acheive in dates [i..N - 1] and also am NOT holding a stock in Ith day and also current day is not a cooldown
// dp[i][!own][!cool] = max(dp[i + 1][!own][!cool], dp[i + 1][own][!cool] - prices[i])
//                      max(leave it, buy it on current day)


// Cool -> yes 1 , no 0
// Own  -> yes 1 , no 0


class Solution {
public:
    
    int solve(vector<int>& prices, int i, bool own, bool cool, vector<vector<vector<int>>> &dp){
        
        if(i == prices.size()){
            return 0;
        }
        
        if(dp[i][own][cool] != -1)
            return dp[i][own][cool];
        
        if(own){
            int holdIt = solve(prices, i + 1, 1, 0, dp);
            int sellToday = solve(prices, i + 1, 0, 1, dp) + prices[i];
            int better = max(holdIt, sellToday);
            return dp[i][own][cool] = dp[i][own][!cool] = better;
        }else{
            if(cool){
                return dp[i][own][cool] = solve(prices, i + 1, 0, 0, dp);
            }else{
                int leaveIt = solve(prices, i + 1, 0, 0, dp);
                int buyToday = solve(prices, i + 1, 1, 0, dp) - prices[i];
                int better = max(leaveIt, buyToday);
                return dp[i][own][cool] = better;
            }
        }
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(prices, 0, 0, 0, dp);
    }
};