// PROBLEM :- https://leetcode.com/problems/next-greater-element-i/

// LEETCODE | EASY | ARRAY

// Solution :- T.C. O(N + M) S.C. O(M)

// In NUMS2, find out the monotonic increasing sequence. With each element in the sequence, its next greater is the corresponding next element of sequence.
// Based on it, place the corresponding answers in NUMS1.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nextGreater;
        
        int prev = nums2[0];
        for(int i = 1 ; i < nums2.size() ; i++){
            if(nums2[i] > prev){
                nextGreater[prev] = nums2[i];
                prev = nums2[i];
            }
        }
        
        vector<int> ans;
        for(int i = 0 ; i < nums1.size() ; i++){
            if(nextGreater.count(nums1[i]) == 1){
                ans.push_back(nextGreater[nums1[i]]);
            }else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};