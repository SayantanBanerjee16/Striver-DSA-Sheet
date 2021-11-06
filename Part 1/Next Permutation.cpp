// PROBLEM :-
// https://leetcode.com/problems/next-permutation/

// LEETCODE | MEDIUM | ARRAY

// Optimized Approach : T.C O(N) S.C O(1)

// Step 1: Linearly traverse array from backward such that ith index value of the array is less than (i+1)th index value. Store that index in a variable.

// Step 2: If the index value received from step 1 is less than 0. This means the given input array is the largest lexicographical permutation. Hence, we will reverse the input array to get the minimum or starting permutation. Linearly traverse array from backward. Find an index that has a value greater than the previously found index. Store index another variable.

// Step 3: Swap values present in indices found in the above two steps.

// Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int index = -1;
        
        for(int i = nums.size() - 1 ; i > 0 ; i--){
            if(nums[i - 1] < nums[i]){
                index = i;
                break;
            }
        }

        
        if(index == -1){
            reverse(nums.begin(), nums.end());
        }else{
            reverse(nums.begin() + index, nums.end());
            for(int i = index ; i < nums.size() ; i++){
                if(nums[i] > nums[index - 1]){
                    swap(nums[i], nums[index - 1]);
                    break;
                }
            } 
        }
            
    }
};