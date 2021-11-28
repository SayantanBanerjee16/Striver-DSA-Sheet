// PROBLEM :- https://leetcode.com/problems/implement-stack-using-queues/

// LEETCODE | EASY | STACK, QUEUE

// Solution 1 :- T.C. O(N) amortized S.C. O(N)

// Formulate stack using 2 queues.
// PRIMARY queue will store the values as it is supposed to store in a stack.
// Here FRONT of PRIMARY queue, returns the top of the stack.
// And POP of PRIMARY queue, pops the top element of the stack.
// BUT if we directly use PUSH of queue, it will push the element at the back of queue, instead of queue.
//      Here another queue comes into picture. We empty all of the PRIMARY queue elements into another AUXILIARY queue, push the current element in the PRIMARY queue, and then empty all of the AUXILIARY queue elements into PRIMARY queue.

class MyStack {
public:
    
    queue<int> primary;
    queue<int> auxiliary;
    
    MyStack() {
        
    }
    
    void push(int x) {
        while(!primary.empty()){
            auxiliary.push(primary.front());
            primary.pop();
        }
        primary.push(x);
        while(!auxiliary.empty()){
            primary.push(auxiliary.front());
            auxiliary.pop();
        }
    }
    
    int pop() {
        int top = primary.front();
        primary.pop();
        return top;
    }
    
    int top() {
        return primary.front();
    }
    
    bool empty() {
        return primary.empty();
    }
};

// Solution 2 :- T.C. O(N) amortized S.C. O(1)

// Formulate stack using a single queue.
// The queue will store the values as it is supposed to store in a stack.
// Here FRONT of queue, returns the top of the stack.
// And POP of queue, pops the top element of the stack.
// BUT if we directly use PUSH of queue, it will push the element at the back of queue, instead of queue.

// 3 -> 2 -> 1
// INSERT 4
// 4 can be inserted at right only in queue!
// Reverse the queue!
// 1 -> 2 -> 3 
// Push 4
// 1 -> 2 -> 3 -> 4
// Reverse again
// 4 -> 3 -> 2 -> 1
// There you go!

// How to reverse?
// What we do is recursively at each iteration, we pop the value of the queue, and then recurse and repeat the process until the queue is empty. When it is empty, we backtrack and insert the popped out value at each recursion call.

class MyStack {
public:
    
    queue<int> que;
    
    MyStack() {
        
    }
    
    void reverseRecursively(queue<int> &que){  
        if(que.empty())
            return;
        int current_top = que.front();
        que.pop();
        reverseRecursively(que);
        que.push(current_top);
    }
    
    void push(int x) {
        reverseRecursively(que);
        que.push(x);
        reverseRecursively(que);
    }
    
    int pop() {
        int top = que.front();
        que.pop();
        return top;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};