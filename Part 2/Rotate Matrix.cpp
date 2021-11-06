// PROBLEM :-
// https://leetcode.com/problems/rotate-image/

// LEETCODE | MEDIUM | MATRIX GEOMETRY


// Solution 1 : T.C. O(N^2) S.C O(N^2) (Brute)
// Do as directed in external matrix. Not INPLACE.


// Solution 2 : T.C. O(N^2) -> 2 pass S.C O(1)
// Transpose the Matrix along main diagonal. And reverse each rows.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
     
        // transpose matrix
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < row ; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        
        // reverse each rows
        for(int row = 0 ; row < n ; row++){
            int left = 0;
            int right = n - 1;
            while(left < right){
                swap(matrix[row][left], matrix[row][right]);
                left++;
                right--;
            }
        }
    }
};

// Solution 3 :- T.C. O(N^2) -> 1 pass S.C O(1)
// Rotate all the 4 position of each equivalence square.
// Observe mathematically to get the required positions. (see code).


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
     
        for(int row = 0 ; row < n / 2 ; row++){
            for(int col = row ; col < n - 1 - row ; col++){
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[n - 1 - col][row]; 
                matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col];
                matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row];
                matrix[col][n - 1 - row] = tmp;
            }
        }
    }
};+