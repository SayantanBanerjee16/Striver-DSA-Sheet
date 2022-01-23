// PROBLEM :- https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#

// GFG | EASY | GRAPHS DFS

// Solution :- T.C. O(V + E) S.C. O(V + E)
// Basic recursive DFS traversal.

void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &output) {
    visited[node] = true;
    output.push_back(node);

    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (visited[child] == false) {
            dfs(child, adj, visited, output);
        }
    }

}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {

    vector<int> output;
    vector<bool> visited(V, false);

    dfs(0, adj, visited, output);

    return output;
}
