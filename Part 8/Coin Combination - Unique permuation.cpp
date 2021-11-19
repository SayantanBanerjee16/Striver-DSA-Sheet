// PROBLEM :- https://leetcode.com/problems/coin-change-2/

// LEETCODE | MEDIUM | DP

// Solution :- T.C. O(N * A)  S.C. O(N * A)
 
// Form a 2D Matrix {Coins array X Amount}

// Now general idea is :- No of ways at{using upto Ith coin, uisng Jth Amount} 
//                        = No of ways at{using upto (Ith - 1) coin, uisng Jth Amount} 
//                        = + No of ways at{using upto (Ith) coin, uisng (Jth - current coin value) Amount}

// That is No of ways at current position = No of ways WITHOUT using that coin with same amount 
//                                          + No of ways WITH using that coin with leftover amount

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        sort(coins.begin(), coins.end());
        
        int N = coins.size();
        
        vector<vector<int>> dp(N + 1, vector<int>(amount + 1, 0));
        
        for(int i = 0 ; i <= N ; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= amount ; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - coins[i - 1] >= 0){
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        
        return dp[N][amount];
    }
};