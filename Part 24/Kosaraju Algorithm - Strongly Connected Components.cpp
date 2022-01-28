// PROBLEM :- https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// GFG | MEDIUM | GRAPHS SCC

// T.C. O(V + E) S.C. O(V + E)

// To get the SCC count :-

// First have the TopoSort Order from the given graph.
// Well as it is not a DAG, we wont get the proper TopoSort order,
// but it will help us in identifying which region is before which region.

// Now based on the TopoSort order, run DFS on reversed graph.
// Mark all the nodes that can be marked, these all nodes belong to current SCC.

// Now repeat this process until you mark all the nodes, i.e. fetch all the SCC.

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &order) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (visited[child] == false) {
            dfs(child, adj, visited, order);
        }
    }
    order.push(node);
}

void dfsSCC(int node, vector <vector<int>> &reverseAdj, vector<bool> &visitedSCC) {
    visitedSCC[node] = true;
    for (int i = 0; i < reverseAdj[node].size(); i++) {
        int child = reverseAdj[node][i];
        if (visitedSCC[child] == false) {
            dfsSCC(child, reverseAdj, visitedSCC);
        }
    }
}

int kosaraju(int N, vector<int> adj[]) {

    vector <vector<int>> reverseAdj(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int u = i;
            int v = adj[i][j];
            reverseAdj[v].push_back(u);
        }
    }

    stack<int> order;

    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            dfs(i, adj, visited, order);
        }
    }

    vector<int> topoSortOrder;

    while (!order.empty()) {
        int tp = order.top();
        order.pop();
        topoSortOrder.push_back(tp);
    }


    vector<bool> visitedSCC(N, false);
    int sccCount = 0;
    for (int i = 0; i < N; i++) {
        if (visitedSCC[topoSortOrder[i]] == false) {
            sccCount++;
            dfsSCC(topoSortOrder[i], reverseAdj, visitedSCC);
        }
    }

    return sccCount;
}