// PROBLEM :- https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#

// GFG | MEDIUM | BELLMAN-FORD -> Shortest distance from Source with Negative edges but no negative cycle

// T.C. O(V * E) S.C. O(V)

// Logic :- Initialize a distance array with INT_MAX and also distance[S] = 0
// Now repeat N - 1 times and try to relax edges.
// It is guaranteed that if there is NO negative weight cycle, all edges would be maximized relaxed in N - 1 times.
// Proof it by taking a Linear chain as worst case. (or doing a BFS expansion from center)

// Side note :- If there was relaxation in Nth time, it confirms of a negative edge cycle.

// Relaxation meaning :- (U -> V) if Dist[V] can be updated to Dist[U] + wt(U->V). 
// In the previous iteration, maybe Dist[U] got decreased, resulting in decreement of dist[V] in current iteration.

class Solution{
	public:

    vector <int> bellman_ford(int N, vector<vector<int>> &edges, int S) {
        
        int MAXE = 1e8;
        
        vector<int> distance(N, MAXE);
        distance[S] = 0;
        
        int M = edges.size();
        
        for(int repeat = 0 ; repeat <= N - 1 ; repeat++){
            for(int i = 0 ; i < M ; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                
                if(distance[u] != MAXE){
                    distance[v] = min(distance[v] , wt + distance[u]);
                }
                
            }
        }
        
        return distance;
        
    }
};