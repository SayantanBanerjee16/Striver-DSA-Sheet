// PROBLEM :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#

// GFG | MEDIUM | DIJKSTRA ALGO -> Shortest distance from Source to All nodes provided NO NEGATIVE WEIGHT

// T.C. O((V + E)log(V + E)) S.C. O(V)

// Use a distance array and initialize all to INT_MAX and Source to 0.
// Now use a Min-Heap based Priority Queue to store the shortest distance and node executed so far.

// Let's say we have a node A and dist[A] = XY.
// Now traverse in all childs of A, and try to relax the child nodes.
// If child node is relaxed, insert the child into PQ.

// Repeat until PQ is empty.

// One thing to note :- 
// Maybe a single child can be updated by two differnt parents,
// but both maybe present in PQ. 
// To avoid repeatation, ignore the child node in PQ whose distance value doesn't match with the node's current distance value.


class Solution
{
	public:
    vector <int> dijkstra(int N, vector<vector<int>> adj[], int S)
    {
        
        vector<int> distance(N, INT_MAX);
        distance[S] = 0;
        
        using pii = pair<int, int>;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap -> pair<distance, node_number>
        
        pq.push(make_pair(0, S));
        
        while(!pq.empty()){
            
            pii cur = pq.top();
            int cur_dist = cur.first;
            int cur_node = cur.second;
            pq.pop();
            
            if(distance[cur_node] != cur_dist)
                continue;
                
            for(int i = 0 ; i < adj[cur_node].size() ; i++){
                
                int dest = adj[cur_node][i][0];
                int wt = adj[cur_node][i][1];
                
                if(distance[dest] > distance[cur_node] + wt){
                    distance[dest] = distance[cur_node] + wt;
                    pq.push(make_pair(distance[dest], dest));
                }
                
            }
            
        }
        
        return distance;
    }
};