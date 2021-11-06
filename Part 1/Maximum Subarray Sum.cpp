// Problem :-
// https://leetcode.com/problems/maximum-subarray/

LEETCODE | EASY | DP / DIVIDE nd CONQUER


// Solution 1 :-
// KADANE ALGORITHM :- T.C. O(N), S.C. O(1)

// General observation

// At an index i, what can be the optimal ans upto this place? (storing this in MAX_ENDING_HERE variable)
//          Take this value and add with the previous optimal max sum value.
// Now compare MAX_ENDING_HERE with MAX_VAL, and update MAX_VAL appropriately.

// What if MAX_ENDING_HERE < 0 after this current position, 
// it can't contribute any furthur to next iterations as it would make the overall sum less,
// so we do MAX_ENDING_HERE = 0;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int maxEndingHere = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            maxEndingHere += nums[i];
            
            if(maxEndingHere > maxVal){
                maxVal = maxEndingHere;
            }
            
            if(maxEndingHere < 0){
                maxEndingHere = 0;
            }
            
        }
        
        return maxVal;
    }
};



// Solution 2 :-
// DIVIDE AND CONQUER :- T.C. O(NlogN), S.C. O(1)

// General observation

// Take the whole array, divide into two half.
// Take the maximum of:
//      Left subarray recursive
//      Right subarray recursive
//      Max subarray sum of the current subarray passing through the mid-point.



class Solution {
public:
    
    int sumThroughMidOfCurSubarray(vector<int>& nums, int low, int mid, int high){
        int leftPartMax = INT_MIN;
        int leftPartCur = 0;
        
        for(int i = mid ; i >= low ; i--){
            leftPartCur += nums[i];
            leftPartMax = max(leftPartMax, leftPartCur);
        }
        
        int rightPartMax = INT_MIN;
        int rightPartCur = 0;
        for(int i = mid + 1 ; i <= high ; i++){
            rightPartCur += nums[i];
            rightPartMax = max(rightPartMax, rightPartCur);
        }
        
        return leftPartMax + rightPartMax;
    }
    
    
    int recurse(vector<int>& nums, int low, int high){
        
        if(low > high){
            return 0;
        }
        
        if(low == high){
            return nums[low];
        }
        
        int mid = (high + low) >> 1;
        
        int leftValue = recurse(nums, low, mid);
        int rightValue = recurse(nums, mid + 1, high);
        int curSubarrayThroughMid = sumThroughMidOfCurSubarray(nums, low, mid, high);
        
        return max(curSubarrayThroughMid, max(leftValue, rightValue));
        
    }
    
    int maxSubArray(vector<int>& nums) {
        
        return recurse(nums, 0 , nums.size() - 1);
        
    }
};
