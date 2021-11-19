// PROBLEM :- https://leetcode.com/problems/coin-change/

// LEETCODE | MEDIUM | DP

// Solution :- T.C. O(Amount * Coins Length) S.C. O(Amount)

// Build up a DP array and check for all amounts from 1 to AMOUNT.
// At any current amt. X, check with all the coins values, i.e, general equation (dp[X - coins[i]] + 1). 
// Take the one with minimum coin denominations.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1 ; i <= amount ; i++){
            
            for(int j = 0 ; j < coins.size() ; j++){
                
                if(i - coins[j] >= 0){
                    if(dp[i - coins[j]] != INT_MAX)
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }else{
                    break;
                }
                
            }
            
        }
        
        if(dp[amount] == INT_MAX){
            return -1;
        }else{
            return dp[amount];
        }
        
    }
};