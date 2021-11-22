// PROBLEM :- https://leetcode.com/problems/permutations-ii/

// LEETCODE | MEDIUM | BACKTRACKING

// Solution :- T.C. and S.C. O(N!)

// Approach :- Lets say, we have [1 2 4 1 2 3 4 4]
// We have two 1, two 2, one 3, and three 4.
// To avoid repetition of equivalent sets,
// at the first position there should be only one instance of each group, i.e, 1,2,3,4.

// Once the first position is build up, perform the same logic over the rest of the array recursively.
// Build up the sequence, and at the end of each iteration (all elements used), add to the output vector,
// and then backtrack to get other sequence.


class Solution {
public:
    
    void recurse(int used, unordered_map<int,int> freq, vector<int> &current, int N, vector<vector<int>> &output){
        
        if(used == N){
            output.push_back(current);
            return;
        }
        
        for(auto itr : freq){
            if(itr.second != 0){
                int val = itr.first;
                freq[val]--;
                current.push_back(val);
                recurse(used + 1, freq, current, N, output);
                current.pop_back();
                freq[val]++;
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int N = nums.size();
        vector<vector<int>> output;
        vector<int> current;
        
        unordered_map<int, int> freq;
        
        for(int i = 0 ; i < N ; i++){
            freq[nums[i]]++;
        }
        
        recurse(0, freq, current, N, output);
        
        return output;
    }
};