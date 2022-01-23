// PROBLEM :- https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// CODE TUDIO | MEDIUM | GRAPHS , CYCLES

// Solution 1 :- T.C. O(V + E) S.C. O(V + E) -> DFS

// Cycle checking by DFS.
// Pass current node and parent of node, if at any moment, we reach a child node which is already visited 
// and that child node is not the parent of the node, we conclude that Cycle is present in this undirected graph.

bool dfsCycleCheck(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited){
    
    visited[node] = true;
    
    for(int i = 0 ; i < adj[node].size() ; i++){
        int child = adj[node][i];
        if(visited[child] == true && child != parent){
            return true;
        }
        if(visited[child] == false){
            if(dfsCycleCheck(child, node, adj, visited))
                return true;
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n);
    
    for(int i = 0 ; i < m ; i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    vector<bool> visited(n, false);
    
    for(int i = 0  ; i < n ; i++){
        if(visited[i] == false){
            if(dfsCycleCheck(i , -1, adj, visited)){
                return "Yes";
            }
        }
    }
    
    return "No";
}

// Solution 2 :- T.C. O(V + E) S.C. O(V + E) -> BFS

// Cycle checking by BFS. Use a pair to store current node and parent of the current node.
// If anytime, we reach a node's child which is already visited, then we say that a cycle is present.

bool bfsCycleCheck(int node, vector<vector<int>> &adj, vector<bool> &visited){
    
    queue< pair<int, int> > bfs; // stores <node, parent>
   
    bfs.push(make_pair(node, -1));
    
    while(!bfs.empty()){
        
        int curNode = bfs.front().first;
        int curNodeParent = bfs.front().second;
        visited[curNode] = true;
        bfs.pop();
        
        for(int i = 0 ; i < adj[curNode].size() ; i++){
            int child = adj[curNode][i];
            if(visited[child] == true && child != curNodeParent){
                return true;
            }
            if(visited[child] == false){
                bfs.push(make_pair(child, curNode));
            }
        }
        
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n);
    
    for(int i = 0 ; i < m ; i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    vector<bool> visited(n, false);
    
    for(int i = 0  ; i < n ; i++){
        if(visited[i] == false){
            if(bfsCycleCheck(i , adj, visited)){
                return "Yes";
            }
        }
    }
    
    return "No";
}

// Solution 3 :- T.C. O(Vlog*V) S.C. O(V) -> MOST OPTIMIZED -> UNION - FIND SOLUTION

// First we observe that any undirected graph of V nodes can have at max V - 1 edges without having cycle.
// If number of edges is >= V, we can safely assume, cycle is present.

// Now we will traverse in all the edges, and try to merge the two components of the edge using Union Find.
// If both component is already in a same component before merging, we can safely conclude, Cycle is present.

// After merging all the edges components, we can conclude No cycle is present.

struct UnionFind {
    int n;
    vector<int> rank;
    vector<int> parent;
    // store other info as required
    UnionFind(int n) {
        rank.resize(n);
        fill(rank.begin(), rank.end(), 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int get(int a) {
        return parent[a] = (parent[a] == a ? a : get(parent[a]));
    }
    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return;
        }
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
        if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
};

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    
    if(m >= n){
        return "Yes";
    }
    
    UnionFind* uf = new UnionFind(n + 1);
    
    for(int i = 0 ; i < m ; i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        if(uf->get(u) == uf->get(v)){
            return "Yes";
        }
        
        uf->merge(u, v);
        
    }
    
    return "No";
}

