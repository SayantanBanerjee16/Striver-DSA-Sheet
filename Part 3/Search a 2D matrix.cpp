// PROBLEM :- 
// https://leetcode.com/problems/search-a-2d-matrix/

// LEETCODE | MEDIUM | MATRIX BINARY SEARCH KINDA


// Solution 1 :- Brute -> Linear Scan T.C O(NM) S.C O(1)

// Solution 2 :- Optimized solution T.C O(N+M) S.C O(1)

// Start from Top - Right Corner.
// At any position,
//      if arr[i][j] is less than required number, go down.
//      if arr[i][j] is more than required number, go left.
//	Observe this diagrammatically why!

// If anywhere between target is fetched, awesome, return true. Else return false.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j = matrix[0].size() - 1;
        int i = 0;
        
        while(i < matrix.size() && j >= 0){
            
            if(target == matrix[i][j]){
                return true;
            }
            
            if(target < matrix[i][j]){
                j--;
            }else if(target > matrix[i][j]){
                i++;
            }
            
        }
        
        return false;
    }
};