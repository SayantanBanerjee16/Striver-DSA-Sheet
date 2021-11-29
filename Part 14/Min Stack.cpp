// Problem :- https://leetcode.com/problems/min-stack/

// LEETCODE | EASY | STACK

// Solution :- T.C. O(1) per operation S.C. O(N) Aux space :- O(1)

// Mantain a stack with pair of values. The former is for holding value at the top of stack, and the latter is for holding the minimum of the stack upto that point.

// PUSH    -> push another element {current value, min(current value, min of stack previously)}
// POP     -> pop top element
// TOP     -> return top element first value
// GET MIN -> return top element second value which actually holds the minimum value of stack upto that point.

class MinStack {
public:
    
    stack<pair<int, int>> minStack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        int curMinimum = min(val, minStack.top().second);
        minStack.push({val, curMinimum});
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};
