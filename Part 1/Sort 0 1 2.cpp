// PROBLEM LINK :-
// https://leetcode.com/problems/sort-colors/

LEETCODE | MEDIUM | ARRAY - POINTERS

// Solution 1 :- Sort it simply. T.C O(NlogN) S.C O(1)
// Solution 2 :- Use Count Sort Technique. T.C O(N) S.C O(1) -> 2 pass
//               Count number of 0's 1's and 2's. And fill in the array accordingly.


// Solution 3 :- OPTIMIZED T.C O(N) S.C O(1) -> 1 pass
// Intuition logic :
// 3 pointers -> low, mid, high

// at each stage
// 0 to low - 1 -> all zeroes
// high + 1 to N - 1 -> all twos
// rest in between -> all 1's. 
// If we fetch 0's or 2's here, then interchange at low pointer or high pointer.


// code logic :

// repeat until mid <= high
// if we encounter mid -> 0, swap(low, mid), increement both pointer
// encounter mid -> 1, increement mid pointer
// encounter mid -> 2, swap (mid, high), and just decreement high pointer

class Solution {
public:

    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid <= high){
            
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }else if(nums[mid] == 1){
                mid++;
            }else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            
        }
        
    }
};