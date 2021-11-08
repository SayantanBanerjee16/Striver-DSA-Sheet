// PROBLEM:-
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// LEETCODE | EASY | GREEDY

// Approach -> Greedily store the minimum one and choose the maximum one present after the cur minimum.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        
        for(int i = 0 ; i < prices.size() ; i++){
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i] - minPrice);
        }
        
        return ans;
        
    }
};