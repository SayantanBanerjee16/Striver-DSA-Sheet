// PROBLEM :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

// GFG | MEDIUM | MST -> PRIM

// T.C. O(ElogV) S.C. O(E + V)

// Base Logic -> Add node by node to MST. From set of all nodes currently present in partial-MST,
//               choose the edge with minimum weight from all the edges connected from this partial-MST nodes to all other nodes.


// Use 3 array -> key[] parent[] and mstSet[]

// mstSet[] -> refers to which nodes are already set in MST. 
//             Initially set all nodes to FALSE and key[0] = TRUE
// key[]    -> refers to the effective weight to get that node from all the MST set nodes
//             Initially set all key[] to INT_MAX and key[0] = 0
// parent[] -> Refers which node gets connected to which other node in MST. 
//             Initially set all nodes in parent to -1.

// Use a MIN-HEAP which stores <key[node], node>

// Now repeatedly, use the current min key node, and try to relax keys for the child nodes wich are not in MST currently,
// and if there was a relaxation then relax it, and push to PQ.

// How to calculate MST weight sum?
// Traverse through all the keys, and if it is NOT INT_MAX, then include it in MST weight sum.


// NOTE ON T.C.:-
// The time complexity of the above code/algorithm looks O(V^2) as there are two nested while loops. 
// If we take a closer look, we can observe that the statements in inner loop are executed O(V+E) times (similar to BFS). 
// The inner loop has decreaseKey() operation which takes O(LogV) time. 
// So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV) 


class Solution
{
	public:
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        int parent[N+1]; 
          
        int key[N+1]; 
          
        bool mstSet[N+1]; 
      
        for (int i = 0; i <= N; i++) 
            key[i] = INT_MAX, mstSet[i] = false; 
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    
        key[0] = 0; 
        parent[0] = -1; 
        pq.push({0, 0});
        
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            
            mstSet[u] = true; 
            
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
    		        key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
                
        }
        
        int mstWeight = 0;
        for(int i = 1;i<=N;i++) {
            if(key[i] != INT_MAX) 
                mstWeight += key[i];
        }
        return mstWeight;
    }
};