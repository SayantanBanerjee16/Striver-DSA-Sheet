// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1#

// GFG | MEDIUM | FLOYD WARSHALL -> Shortest path between any two nodes

// Solution :- T.C. O(N^3) S.C. O(1)

// Logic is between two nodes A to B, we will check for all nodes C, D, E, F,... etc
// so that dist[A][B] = min(dist[A][B] , dist[A][X] + dist[X][B])

// Note that use dist[A][X]  and dist[X][B] only when it is not -1
// And also at start dist[A][B] == -1, then replace with any valid distance.

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int N = matrix.size();
	    
	    for(int k = 0 ; k < N ; k++){
	        for(int i = 0 ; i < N ; i++){
	            for(int j = 0 ; j < N ; j++){
	                if(matrix[i][k] != -1 && matrix[k][j] != -1){
	                    if(matrix[i][j] == -1){
	                        matrix[i][j] = matrix[i][k] + matrix[k][j];
	                    }else{
	                        matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	                    }
	                }
	            }
	        }
	    }
	    
	}
};
