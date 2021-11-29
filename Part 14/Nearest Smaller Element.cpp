// PROBLEM :- https://www.interviewbit.com/problems/nearest-smaller-element/

// INTERVIEW BIT | EASY | MONOTONIC STACK

// Solution :- T.C. O(N) S.C. O(N)

// Logic :- 
// Mantain a monotonic stack.
// While pushing the current element, all the elements present at top of stack which is greater than the current element value, pop that out.
// After all the popping operation, if stack is empty, NEAREST SMALLER is not present. Else the top of stack contributes to NEAREST SMALLER.
// In this way, we are mantaining the stack which converse in to finding the nearest smaller element.

vector<int> Solution::prevSmaller(vector<int> &nums) {

    stack<int> stk;
    vector<int> ans;

    for(int i = 0 ; i < nums.size() ; i++){
        while(!stk.empty() && (stk.top() >= nums[i])){
            stk.pop();
        }

        if(stk.empty()){
            ans.push_back(-1);
        }else{
            ans.push_back(stk.top());
        }

        stk.push(nums[i]);

    }

    return ans;

}