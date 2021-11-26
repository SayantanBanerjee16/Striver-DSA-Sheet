// PROBLEM :- https://leetcode.com/problems/search-in-rotated-sorted-array/

// LEETCODE | MEDIUM | BINARY SEARCH

// Observation 1 :- Any rotated sorted array can be divided into 2 sorted array.
//                        Find that pivot point.

// Observation 2 :- Pivot element A[pivot - 1] > A[pivot].
//                  Rest all elemeents are A[x - 1] < A[x].
//                  Use this to simulate B.S. break condition.

// How to reduce search space?
// Pivot element will be the smallest element of the whole array. 
// compare A[mid] with A[0], reduce search space accordingly.

// Once Pivot is found, binary search on the basis of the proximity of the element to either left or right of Pivot.

// Edge case :- What if array is not rotated!!

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1; // not present
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(nums[0] <= nums[n - 1]){
            // not rotated
            return binarySearch(nums, 0, n - 1, target);
        }
        
        int low = 0;
        int high = n - 1;
        
        int rotatedIndex = -1;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            if(mid == 0){
                break;
            }else if(nums[mid] < nums[mid - 1]){
                rotatedIndex = mid;
                break;
            }else if(nums[mid] < nums[0]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        if(rotatedIndex == -1){
            rotatedIndex = high;
        }
        
        if(target < nums[0]){
            // search in right hand side of pivot
            return binarySearch(nums, rotatedIndex, n - 1, target);
        }else{
            // search in left hand side of pivot
            return binarySearch(nums, 0, rotatedIndex - 1, target);
        }
        
    }
};


