// PROBLEM :- https://leetcode.com/problems/maximum-product-subarray/

// LEETCODE | MEDIUM | DP

// Solution :- T.C. O(N) S.C. O(1)

// Modified Kadane Algorithm. 

// NEGATIVE * NEGATIVE = POSITIVE
// POSITIVE * POSITIVE = POSITIVE

// So at every point, keep the maximum acheived and mimimum acheived.
// At particular location, update the maximum and minimum. 

// Answer is the maximum of all the traversal_maximum acheived.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        int mx = nums[0];
        int mn = nums[0];
        
        int ans = mx;
        
        for(int i = 1; i<n; i++){
            
            int prev_max = mx;
            int prev_min = mn;
            
            mx = max(nums[i], max(nums[i] * prev_max , nums[i] * prev_min));
            mn = min(nums[i], min(nums[i] * prev_max , nums[i] * prev_min));
            
            ans = max(ans, mx);
        }
        return ans;
    }
};