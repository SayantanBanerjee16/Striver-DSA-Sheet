// PROBLEM :- https://leetcode.com/problems/longest-increasing-subsequence/

// LEETCODE | MEDIUM | DP , BINARY SEARCH

// Solution 1 :- T.C. O(N^2) S.C. O(N)

// For every location, check the previous locations, and if any number is smaller than the current,
// store mx = max(mx , dp[j] + 1) where j is the location of that smaller element.
// Finally dp[i] = mx;

// Base case :- dp[0] = 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size() , 1);
        dp[0] = 1;
        
        for(int i = 1 ; i < nums.size() ; i++){
            int mx = 1;
            for(int j = i - 1 ; j >= 0 ; j--){
                if(nums[j] < nums[i] && mx < dp[j] + 1){
                    mx = dp[j] + 1;
                }
            }
            dp[i] = mx;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

// Solution 2 :- T.C. O(NlogN) S.C. O(N)

// Mantain the vector of LIS.
// Whenever a new element comes, find the lower bound of that element, 
// and replace the previous found element with the current one
// OR if the lower bound refers to the end of the vector, add the new element to the vector.

// NOTE :- Finally found sequence is not a valid LIS from the given array. This approch only guarantees us LIS length in NlogN.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            
            if(it==res.end()) 
                res.push_back(nums[i]);
            else 
                *it = nums[i];
        }
        return res.size();
    }
};