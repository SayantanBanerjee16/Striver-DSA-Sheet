// PROBLEM:-
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// LEETCODE | MEDIUM | GREEDY

// T.C :- O(N) S.C :- O(1)

// Claim -> If there is an upward infletion between two days, accept it. 

// Proof ->
// Suppose there is a LIS A -> B -> C -> D, 
// what are we saying is accept the stock on A, and sell on D, i.e, ans += D - A.
// To code it simply, we dont have to track these extremities, instead D - A = (D - C) + (C - B) + (B - A).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        
        for(int i = 1 ; i < prices.size() ; i++){
            if(prices[i] > prices[i - 1]){
                ans += prices[i] - prices[i - 1];
            }
        }
        
        return ans;
        
    }
};