// PROBLEM:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// LEETCODE | HARD | DP

// T.C :- O(N) , S.C O(N)

// dp[i][own][j] -> max amount we can acheive in dates [i..N - 1] and also am holding a stock in Ith day, with j transaction remaining
// dp[i][own][j] = max(dp[i + 1][own][j], dp[i + 1][!own][j - 1] + prices[i])
//                 max(hold it, sell it on current day)


// dp[i][!own][j] ->  max amount we can acheive in dates [i..N - 1] and also am NOT holding a stock in Ith day,  with j transaction remaining
// dp[i][!own][j] = max(dp[i + 1][!own][j], dp[i + 1][own][j] - prices[i])
//                      max(leave it, buy it on current day)

// What if j (transaction left) becomes 0? -> simply end the iteration there.
// Own  -> yes 1 , no 0

// ans -> dp[0][!own][K] -> dp[0][0][K] 

// This solution won't pass in Leetcode due to constraints.

class Solution {
public:
    int solve(vector<int>& prices, int i, bool own, int J, vector<vector<vector<int>>> &dp){
        
        if(i == prices.size()){
            return 0;
        }
        
        if(J < 0){
            return 0;
        }
        
        if(dp[i][own][J] != -1)
            return dp[i][own][J];
        
        if(own){
            int holdIt = solve(prices, i + 1, 1, J, dp);
            int sellToday = solve(prices, i + 1, 0, J - 1, dp) + prices[i];
            int better = max(holdIt, sellToday);
            return dp[i][own][J] = better;
        }else{
            int leaveIt = solve(prices, i + 1, 0, J, dp);
            int buyToday = solve(prices, i + 1, 1, J, dp) - prices[i];
            int better = max(leaveIt, buyToday);
            return dp[i][own][J] = better;
        }
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int K = 2;
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(prices, 0, 0, K - 1, dp);
    }
};


// Optimized Algo :- T.C O(N) S.C O(1)

// Intuition :-

// How K = 2 would look like ? (Optimized algo in Previous Question)

// Similar to Buy and Sell Stock I, where only one transaction allowed, 
// we keep track the lowest price and once the price exceeds the old lowest price, we record the difference.
// Here, the "oneBuy" keeps track of the lowest price, and "oneBuyOneSell" keeps track of the biggest profit we could get.

// Then the tricky part comes, how to handle the twoBuy? 
// Suppose in real life, you have bought and sold a stock and made $100 dollar profit. 
// When you want to purchase a stock which costs you $300 dollars, how would you think this? 
// You must think, um, I have made $100 profit, so I think this $300 dollar stock is worth $200 FOR ME since I have hold $100 for free.
// There we go, you got the idea how we calculate "twoBuy". We just minimize the cost again. The "twoBuyTwoSell" is just making as much profit as possible.

// Now generaize this upto K transaction.

// Credits :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1)./242914


class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        
        if(k == 0 || N < 2){
            return 0;
        }
        
        vector<int> buy(k, INT_MAX);
        vector<int> buyAndSell(k, 0);
        
        for(int i = 0 ; i < N ; i++){
            int cur = prices[i];
            
            buy[0] = min(buy[0], cur);
            buyAndSell[0] = max(buyAndSell[0], cur - buy[0]);
                
            for(int j = 1 ; j < k ; j++){
                buy[j] = min(buy[j], cur - buyAndSell[j - 1]);
                buyAndSell[j] = max(buyAndSell[j], cur - buy[j]);
            }
        }
        
        return buyAndSell[k - 1];
    }
};