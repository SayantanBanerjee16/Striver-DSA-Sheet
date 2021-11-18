// PROBLEM :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// LEETCODE | EASY | TWO POINTERS

// Solution :- T.C O(N) S.C O(1)

// Traverse and replace the newmost non - duplicate value at the leftmost available position.
// Update pointer accordingly.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int prevValue = nums[0];
        int nonDuplicatedValues = 1;
        int positionToReplace = 1;
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != prevValue){
                nums[positionToReplace] = nums[i];
                positionToReplace++;
                nonDuplicatedValues++;
                prevValue = nums[i];
            }
        }
        
        return nonDuplicatedValues;
    }
};