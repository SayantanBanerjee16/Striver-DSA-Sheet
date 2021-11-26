// PROBLEM :- https://leetcode.com/problems/median-of-two-sorted-arrays/

// LEETCODE | HARD | BINARY SEARCH

// Solution :- T.C. O(min(log(N,M))) S.C. O(1)

// Full logic -> refer ur own binary search notes OR striver video 
// https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=65

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Binary Searching over the less size
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        
        // Binary search over first array
        int low = 0, high = n1;
        
        while(low <= high) {
            
            // Partition of both array, so that overall Left side contains (n1 + n2 + 1) / 2 elements as total.
            // Rest all elements contains in right side.
            
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            // Getting the values in neighbour of the partition cuts. Handled edge cases in terms of MIN and MAX values so that they are dealt all togetherly.
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            // if valid partition
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; // as mid value is higher, that value must be on right hand side of overall partition. Recurse in left hand search space.
            }
            else {
                low = cut1 + 1; // as mid value is lower, more values must be on left hand side of overall partition. Recurse in right hand search space.
            }
        }
        return 0.0; 
    }
};