// PROBLEM :- https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// CODE STUDIO | MEDIUM | GRAPH, CYCLES

// Solution 1 :- Using DFS -> T.C. O(V + E) S.C. O(V)

// For detection of cycle in a directed graph using DFS, we use Node Colouring technique.
// Node Color 0 -> Not visited node
// Node Color 1 -> DFS was started but still not over
// Node Color 2 -> DFS was started and also exited

// So when we are in some node, and we found its child node to be of color 1, then we conclude, CYCLE EXIST.

bool dfsCycleCheck(int node, vector<int> &nodeColor, vector<vector<int>> &adj){
    nodeColor[node] = 1;
    for(int i = 0 ; i < adj[node].size() ; i++){
        int child = adj[node][i];
        if(nodeColor[child] == 1){
            return true;
        }
        if(nodeColor[child] == 0){
            if(dfsCycleCheck(child, nodeColor, adj)){
                return true;
            }
        }
    }
    nodeColor[node] = 2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    vector<vector<int>> adj(n);
    
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        u--;
        v--;
        adj[u].push_back(v);
    }
    
    vector<int> nodeColor(n, 0);
    
    for(int i = 0 ; i < n ; i++){
        if(nodeColor[i] == 0){
            if(dfsCycleCheck(i, nodeColor, adj)){
                return true;
            }
        }
    }
    
    return false;
}

// Solution 2 :- Using BFS -> T.C. O(V + E) S.C. O(V)

// For detection of cycle in a directed graph using BFS, we use Kahn Algo technique.
// Kahn Algo gives us Topological Sort, and if we are able to get the topo sort order, then we can conclude, cycle is not there.
// Else cycle is present.

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        u--;
        v--;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    int nodesFoundInTopoSortOrder = 0;
    
    queue<int> indegreeZero;
    
    for(int i = 0 ; i < n ; i++){
        if(indegree[i] == 0){
            indegreeZero.push(i);
            nodesFoundInTopoSortOrder++;
        }
    }
    
    while(!indegreeZero.empty()){
        int node = indegreeZero.front();
        indegreeZero.pop();
        for(int i = 0 ; i < adj[node].size() ; i++){
            int child = adj[node][i];
            indegree[child]--;
            if(indegree[child] == 0){
                indegreeZero.push(child);
            	nodesFoundInTopoSortOrder++;
            }
        }
    }
    
    if(nodesFoundInTopoSortOrder == n){
        return false;
    }else{
        return true;
    }
    
}