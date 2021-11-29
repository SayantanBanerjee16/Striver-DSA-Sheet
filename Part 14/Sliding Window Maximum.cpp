// PROBLEM :- https://leetcode.com/problems/sliding-window-maximum/

// LEETCODE | HARD | SLIDING WINDOW, DOUBLE ENDED QUEUE

// Solution :- T.C. O(N) S.C. O(K)

// Maintain a DEQUEUE of at max K size. Always PUSH at the end. But dont store all the values in the DEQUEUE.
// Only mantain the maximum values, and if at BACK of DEQUEUE, the value present is less than that of current one, pop it out.
// It will ensure that the maximum of every window is present at FRONT.
// While traversing from one window to next window, the value which gets removed from previous window, if that is equal to the FRONT of DEQUEUE, then pop it out.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> window;
        
        for(int i = 0 ; i < k - 1 ; i++){
            int cur = nums[i];
            while(!window.empty() && window.back() < cur){
                window.pop_back();
            }
            window.push_back(cur);
        }
        
        vector<int> ans;
        
        for(int i = k - 1 ; i < nums.size() ; i++){
            int cur = nums[i];
            while(!window.empty() && window.back() < cur){
                window.pop_back();
            }
            window.push_back(cur);
            
            int curAns = window.front();
            ans.push_back(curAns);
            
            int poppedOutValue = nums[i - k + 1];
            if(!window.empty() && window.front() == poppedOutValue){
                window.pop_front();
            }
        }
        
        return ans;
        
    }
};