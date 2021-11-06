// PROBLEM :-
// https://leetcode.com/problems/merge-intervals/

// LEETCODE | MEDIUM | ARRAY INTERVALS

// T.C O(NlogN) S.C O(1)

// Approach :-
// First sort the array,
// Suppose from previously you are holding with range [L, R].
// Now check the current range with [L, R].
//      If overlapping / merging, update R = max(R, current_end)
//      Else, take the previous interval, add to the solution vector, and start a new interval [L, R] initializing with current interval.

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1 ; i < intervals.size() ; i++){
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            if(curStart > end){
                ans.push_back({start, end});
                start = curStart;
                end = curEnd;
            }else{
                end = max(end, curEnd);
            }
        }
        
        ans.push_back({start, end});
        return ans;
    }
    
};