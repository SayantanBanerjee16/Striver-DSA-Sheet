// PROBLEM :- https://leetcode.com/problems/implement-queue-using-stacks/

// Solution 1 :- T.C. O(1) Amortized S.C. O(1)

// Formulate queue using a single stack.
// The stack POP and TOP will implement queue's POP and FRONT respectively.
// How to implement PUSH of queue in stack!

// How?
// What we do is recursively, we pop the value of the stack, and then recurse and repeat the process until the stack is empty. When it is empty, we enter the value. After that, we backtrack and insert the popped out value at each recursion call.

class MyQueue {
public:
    
    stack<int> stk;
    
    MyQueue() {
        
    }
    
    void recurse(int x, stack<int> &stk){  
        if(stk.empty()){
            stk.push(x);
            return;
        }
        int current_top = stk.top();
        stk.pop();
        recurse(x, stk);
        stk.push(current_top);
    }
    
    void push(int x) {
        recurse(x, stk);
    }
    
    int pop() {
        int topValue = stk.top();
        stk.pop();
        return topValue;
    }
    
    int peek() {
        int topValue = stk.top();
        return topValue;
    }
    
    bool empty() {
        return stk.empty();
    }
};

// Solution 2 :- Amortized T.C. O(1) S.C. O(N)

// Take 2 stacks, PRIMARY and AUXILIARY.
// PRIMARY will take any incoming PUSH operation at POP.
// PEEK and POP would be done at TOP of AUXILIARY stack. 
//      What if AUXILIARY STACK is empty? Take PRIMARY stack elements and pop one-by-one and insert it into AUX stack. The order gets reverse, and thus TOP of AUX fetches PEEK and POP operation of queue.

// Why Amortized T.C. O(1)?
// Lets us say N PUSH operation FOLLOWED by N pop operation!
//          O(1) for each operation for inserting elements in PRIMARY stack, and then for first pop operation, all elements are popped and inserted into AUX stack, in O(N). But for subsequent N - 1 POP calls, all are done in O(1).
// Overall amortized T.C. O(1)

// Lets us say N PUSH operation ALTERNATED with by pop operation!
//          O(1) for each operation for inserting elements in PRIMARY stack, and then for all pop operation, all elements are popped and inserted into AUX stack, in O(N), but here N = 1.
// Overall amortized T.C. O(1)


class MyQueue {
public:
    
    stack<int> primary, aux;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        primary.push(x);
    }
    
    int pop() { 
        int topValue = peek();
        aux.pop();
        return topValue;
    }
    
    int peek() {
        if(aux.empty()){
            while(!primary.empty()){
                int tp = primary.top();
                aux.push(tp);
                primary.pop();
            }
        }
        
        return aux.top();
    }
    
    bool empty() {
        return primary.empty() && aux.empty();
    }
};
