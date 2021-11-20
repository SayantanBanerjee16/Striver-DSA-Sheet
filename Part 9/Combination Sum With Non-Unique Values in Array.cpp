// PROBLEM :- https://leetcode.com/problems/combination-sum/

// LEETCODE | MEDIUM | BACKTRACKING

// Solution :- T.C. O(2^N) S.C. O(2^N) -> NOT SURE

// First sort the array. So that if after encountering first M elements, you see the SUM is larger than TARGET, you can simply skip the rest of recursing for that iteration.

// Solution is to consider case by either selecting the current position element and recursing on rest.
//                                 or NOT selecting the current position element and recursing on rest.

// If anywhere, Target gets equal to selected elements SUM, then add it to output vector.

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
        
        int indexWithNextVal = N;
        for(int i = pos + 1 ; i < N ; i++){
            if(val != candidates[i]){
                indexWithNextVal = i;
                break;
            }
        }
        
        // take this value
        currentVec.push_back(val);
        recurse(pos + 1, sum + val, currentVec, candidates, output, target, N);
        currentVec.pop_back();
        
        // don't take this value
        recurse(indexWithNextVal, sum, currentVec, candidates, output, target, N);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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