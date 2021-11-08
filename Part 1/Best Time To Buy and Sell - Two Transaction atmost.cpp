// PROBLEM:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// LEETCODE | HARD | DP

// Optimized Algo :- T.C O(N) S.C O(1)

// Intuition :-

// Similar to Buy and Sell Stock I, where only one transaction allowed, 
// we keep track the lowest price and once the price exceeds the old lowest price, we record the difference.
// Here, the "oneBuy" keeps track of the lowest price, and "oneBuyOneSell" keeps track of the biggest profit we could get.

// Then the tricky part comes, how to handle the twoBuy? 
// Suppose in real life, you have bought and sold a stock and made $100 dollar profit. 
// When you want to purchase a stock which costs you $300 dollars, how would you think this? 
// You must think, um, I have made $100 profit, so I think this $300 dollar stock is worth $200 FOR ME since I have hold $100 for free.
// There we go, you got the idea how we calculate "twoBuy". We just minimize the cost again. The "twoBuyTwoSell" is just making as much profit as possible.

// Credits :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1)./242914

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        
        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        int oneBuy = INT_MAX;
        int twoBuy = INT_MAX;
        
        for(int i = 0 ; i < N ; i++){
            int cur = prices[i];
            oneBuy = min(oneBuy, cur);
            oneBuyOneSell = max(oneBuyOneSell, cur - oneBuy);
            twoBuy = min(twoBuy, cur - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, cur - twoBuy);
        }
        
        return twoBuyTwoSell;
    }
};