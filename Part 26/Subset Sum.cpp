// PROBLEM :- https://leetcode.com/problems/partition-equal-subset-sum/

// LEETCODE | MEDIUM | DP

// Solution :- T.C. O(N * sum) S.C. O(N * sum) where sum = sum of all elements of the vector

// First find the total sum of the vector.
// If total sum = ODD, vector cannot be divided into two parts.

// So partitionSum = totalSum / 2.

// Now use the logic for Knapsack 0-1 DP.

// Either use the current element in the partition subset, and check for valid subset with the remaining partitionSum.
// Else discard the current element in the subset, and check for valid subset with the partitionSum.

// Form this recursively solution with memorization and later convert it into tabular solution.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            totalSum += nums[i];
        }
        
        if(totalSum % 2 == 1){
            return false;
        }
        
        int partitionSum = totalSum / 2;
        int N = nums.size();
        
        
        vector<vector<bool>> dp(N + 1, vector<bool>(partitionSum + 1, false));
        
        for(int i = 0 ; i < N + 1 ; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1 ; i < N + 1 ; i++){
            for(int cur_sum = 1 ; cur_sum <= partitionSum ; cur_sum++){
                int cur_value = nums[i - 1];
                if(dp[i - 1][cur_sum] == true || (cur_sum - cur_value >= 0 && dp[i - 1][cur_sum - cur_value] == true)){
                    dp[i][cur_sum] = true;
                }
            }
        }
        
        return dp[N][partitionSum];
        
    }
};