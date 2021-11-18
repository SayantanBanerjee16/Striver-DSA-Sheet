// PROBLEM :- https://leetcode.com/problems/trapping-rain-water/

// LEETCODE | HARD | DP

// Solution 1 :- T.C. O(N) and S.C. O(N)

// At any position, it can store water amount equal to,
// minimum of(Left boundary max height, right boundary max height) - current height.
// Simulate this using Prefix and Suffix Max DP.

class Solution {
public:
    int trap(vector<int>& height) {
        
        int N = height.size();
        
        vector<int> pref(N, 0);
        vector<int>  suf(N, 0);
        
        pref[0] = height[0];
        suf[N - 1] = height[N - 1];
        
        for(int i = 1 ; i < N ; i++){
            pref[i] = max(pref[i - 1], height[i]);
        }
        
        for(int i = N - 2 ; i >= 0 ; i--){
            suf[i] = max(suf[i + 1], height[i]);
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < N ; i++){
            ans += min(pref[i], suf[i]) - height[i];
        } 
        
        return ans;
    }
};