// PROBLEM :-
// https://leetcode.com/problems/pascals-triangle/

LEETCODE | EASY | MATHS

//  Solution 1 :- Greedily do what it refers to do. 
//  Use previous row to formulate the current row.


//  Solution 2 :-
//  Pascal Traingle observation :-
//  First row (n = 0)   :- 0c0
//  Second row (n = 1)  :- 1c0, 1c1,
//  Third row (n = 2)   :- 2c0, 2c1, 2c2
//  Fourth row (n = 3)  :- 3c0, 3c1, 3c2, 3c3
//  And so on...
//  Also nCr = ((nCr-1) * (n - r + 1)) / r
//  Formulate answer using these observation.

//  Advantage of Solution 2 over 1 :- When question asks about any particular row directly.


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < numRows ; i++){
            
            vector<int> cur;
            int temp = 1;
            cur.push_back(temp);
            
            for(int j = 1 ; j <= i ; j++){
                temp = (temp * (i - j + 1)) / j;
                cur.push_back(temp);
            }
            
            ans.push_back(cur);
        }
        
        return ans;
    }
};