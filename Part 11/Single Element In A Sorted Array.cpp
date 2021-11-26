// PROBLEM :- https://leetcode.com/problems/single-element-in-a-sorted-array/

// LEETCODE | MEDIUM | BINARY SEARCH

// Solution 1 :- T.C. O(N) S.C. O(1)
// Find XOR of all the elements. It will give the required answer.

// Solution 2 :- T.C. O(logN) S.C. O(1)

// observe a pattern 
// all the same pairs,
// before the single element, first element is in EVEN index and second element is in ODD index
// after             , first element is in ODD index and second element is in EVEN index

// so simulate a B.S. over the whole array
// take MID - 1, MID, MID + 1 elements together
// if all three are different, MID is the required answer
// else see which two are equal, and according to the observation indexing, reducce the search space accordingly.

// handle the edge cases properly.


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return nums[0];
        }
        
        int low = 0;
        int high = n - 1;
        
        while(low < high){
            
            int mid = (low + high) / 2;
            
            // handle left hand side case
            if(mid == 0){
                if(nums[0] == nums[1]){
                    return nums[2];
                }else{
                    return nums[0];
                }
            }
            
            // handle right hand side case
            if(mid == n - 1){
                if(nums[n - 2] == nums[n - 1]){
                    return nums[n - 3];
                }else{
                    return nums[n - 1];
                }
            }
            
            // handle general case
            
            int leftSide = nums[mid - 1];
            int cur = nums[mid];
            int rightSide = nums[mid + 1];
            
            int firstIndex = -1;
            int secondIndex = -1;
            
            if(leftSide != cur && cur != rightSide){
                return cur; // all three numbers different, return this
                
            }else if(leftSide == cur){
                
                firstIndex = mid - 1;
                secondIndex = mid;
                
            }else{
                
                firstIndex = mid;
                secondIndex = mid + 1;
                
            }
            
            if(firstIndex % 2 == 0){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            
        }
        
        return nums[low];
    }
};