// PROBLEM :- https://leetcode.com/problems/combination-sum/

// LEETCODE | MEDIUM | BACKTRACKING

// Solution :- T.C. O(2^N) S.C. O(2^N) -> NOT SURE

// First sort the array. So that if after encountering first M elements, you see the SUM is larger than TARGET, you can simply skip the rest of recursing for that iteration.

// Solution is to consider case by either selecting the current position element and recursing on rest.
//                                 or NOT selecting the current position element and recursing on rest.

// If anywhere, Target gets equal to selected elements SUM, then add it to output vector.

class Solution {
public:
    
    void recurse(int pos, int sum, vector<int> &currentVec, vector<int>& candidates, vector<vector<int>> &output,  int target, int N){
        
        if(pos == N){
            return;
        }
        
        int val = candidates[pos];
        
        if(sum + val > target){
            return;
        }
        
        if(sum + val == target){
            currentVec.push_back(val);
            output.push_back(currentVec);
            currentVec.pop_back();
            return;
        }
        
        // take this value
        currentVec.push_back(val);
        recurse(pos, sum + val, currentVec, candidates, output, target, N);
        currentVec.pop_back();
        
        // don't take this value
        recurse(pos + 1, sum, currentVec, candidates, output, target, N);
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int N = candidates.size();
        int sum = 0;
        int pos = 0;
        vector<vector<int>> output;
        vector<int> currentVec;
        recurse(pos, sum, currentVec, candidates, output, target, N);
        return output;
    }
};