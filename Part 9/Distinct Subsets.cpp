// PROBLEM :- https://leetcode.com/problems/subsets-ii/

// LEETCODE | MEDIUM | RECURSION

// Solution :- T.C. O(2^N) S.C. O(2^N) -> NOT SURE

// First sort the array.

// Solution is to consider case by either selecting the current position element and recursing on rest.
//                                 or NOT selecting the current position element and recursing on rest.

// ONE IMPORTANT NOTE :- 
// How to remove Duplicates Subsets?
// Let's say you are dealing with 1 1 2 2 2 3 3 (we already sorted the array)
// Let's deal with all the three occurences of 2.
// You might end up with choosing first 2 and second 2  AND in another iteration choosing second 2 and third 2.
// Which are equivalent, and would lead to duplicates.

// Avoid duplicates by, if you are choosing that val, then recurse with the immediate next position.
//                      if you are NOT choosing that val, then recurse with the next position which contains different value.

class Solution {
public:
    
    void recurse(int pos, vector<int>& currentVec, vector<vector<int>>& output, vector<int>& nums, int N){
        
        if(pos == N){
            output.push_back(currentVec);
            return;
        }
        
        int val = nums[pos];
        int indexWithNextVal = N;
        
        for(int i = pos + 1 ; i < N ; i++){
            if(val != nums[i]){
                indexWithNextVal = i;
                break;
            }
        }
        
        // take the value
        currentVec.push_back(val);
        recurse(pos + 1, currentVec, output, nums, N);
        currentVec.pop_back();
        
        // dont take the value
        recurse(indexWithNextVal, currentVec, output, nums, N);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> currentVec;
        
        sort(nums.begin(), nums.end());
        
        recurse(0, currentVec, output, nums, nums.size());
        return output;
    }
};