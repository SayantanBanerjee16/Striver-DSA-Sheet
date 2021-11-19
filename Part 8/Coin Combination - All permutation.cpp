// PROBLEM :- https://cses.fi/problemset/task/1635

// CSES | DP

// Solution :- T.C. O(N * A)  S.C. O(A)
 
// Form a 1D DP {Coins array X Amount}

// Now general idea is :- 
// For every amount, loop over all the coins. 
// Choose a coin, for every valid LEFTOVER amount, 
// dp[current] = summation of no of ways of all valid LEFTOVER amounts.

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        sort(all(coins));
        
        int mod = 1e9 + 7;     

        vector<int> dp(amount + 1, 0);
        dp[0] = 1LL;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < N; j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
                } else {
                    break;
                }
            }
        }

        cout << dp[amount] << endl;
    }
};