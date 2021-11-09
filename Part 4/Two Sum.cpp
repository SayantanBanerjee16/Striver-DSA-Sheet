// PROBLEM:-
// https://leetcode.com/problems/two-sum/submissions/

// LEETCODE | EASY | HASH-MAP ARRAY

// Solution 1 :- Brute -> Nested loop to check for the pair. T.C :- O(N^2) S.C :- O(1)

// Solution 2 :- T.C O(N) S.C. O(N) -> using a Hash-Map.

// Store current fetched nums in the hash-map. 
// Also while traversal check for (target - nums[i]) in the hashmap.
// If fetched, get its index and return.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> storeNums;
        vector<int> output;
        
        for(int i=0; i < nums.size(); i++){
            int remToFind = target - nums[i]  ;
            if (storeNums.find(remToFind) == storeNums.end()) {
                storeNums[nums[i]] = i;
            }else{
                output.push_back(storeNums[remToFind]);
                output.push_back(i);
                break;
            }
        }
        
        return output;
    }
};