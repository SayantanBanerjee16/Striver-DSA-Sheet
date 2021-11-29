// PROBLEM :- https://leetcode.com/problems/online-stock-span/

// LEETCODE | MEDIUM | MONOTONIC STACK

// Solution:- T.C. O(N) S.C. O(N)

// Logic :- 
// Insert the current price and no of days encountered by the current price in the stack.
// In getting a future value, first check if that value is greater than top elements from the stack. 
// If yes, pop that and add those days to this current days. Repeat until the top of stack is greater than current price.

// Such a stack is referred to as monotonic stack.


class StockSpanner {
public:
    
    stack<pair<int, int>> stock; // pair<value, days>
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int curDays = 1;
        while(!stock.empty() && stock.top().first <= price){
            curDays += stock.top().second;
            stock.pop();
        }
        stock.push({price, curDays});
        return curDays;
    }
};