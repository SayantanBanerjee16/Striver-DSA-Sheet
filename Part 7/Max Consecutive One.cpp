// PROBLEM :- https://leetcode.com/problems/max-consecutive-ones/

// LEETCODE | EASY | ARRAY

// Solution :- T.C. O(N) S.C. O(1)

// Traverse and check for the maximum consecutive 1 sequence.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxOne = 0;
        int curOne = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 1){
                curOne++;
            }else{
                maxOne = max(maxOne, curOne);
                curOne = 0;
            }
            
        }
        
        maxOne = max(maxOne, curOne);
        
        return maxOne;
    }
};