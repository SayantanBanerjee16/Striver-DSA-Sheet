// PROBLEM :- https://practice.geeksforgeeks.org/problems/topological-sort/1#

// GFG | MEDIUM | TOPO SORT

// Solution 1 :- T.C. O(V + E) S.C. O(V) -> DFS
// Having a reverse postorder will get out required Topological Sort order.

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &postOrderNodes) {

    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (visited[child] == false) {
            dfs(child, adj, visited, postOrderNodes);
        }
    }

    postOrderNodes.push(node);

}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> postOrderNodes;

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            dfs(i, adj, visited, postOrderNodes);
        }
    }

    vector<int> topoSort;
    while (!postOrderNodes.empty()) {
        topoSort.push_back(postOrderNodes.top());
        postOrderNodes.pop();
    }

    return topoSort;
}

// Solution 2 :- T.C. O(V + E) S.C. O(V) -> BFS -> KAHN ALGO

// If we are talking about a DAG, there must be nodes whose indegree would be 0.
// Remove those nodes first, and you will see other nodes would appear whose indegree is now 0.
// Continue this approach for all the vertices.

// We mantain an indegree vector for all the nodes.
// Whichever indegree comes 0, we will pop that node out and add it to Topo Sort order.
// When we pop some node out, all vertices connected to it gets an reduction in their indegree.
// Push those cgild nodes whose indegree now reaches 0.

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    vector<int> topoSort;

    queue<int> indegreeZero;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            indegreeZero.push(i);
        }
    }

    while (!indegreeZero.empty()) {

        int node = indegreeZero.front();
        indegreeZero.pop();
        topoSort.push_back(node);

        for (int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i];
            indegree[child]--;
            if (indegree[child] == 0) {
                indegreeZero.push(child);
            }
        }
    }

    return topoSort;
}
