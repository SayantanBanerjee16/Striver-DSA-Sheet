// PROBLEM :- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

// GFG | EASY | GRAPHS BFS

// Solution :- T.C. O(V + E) S.C. O(V + E)

// Basic BFS traversal of a graph using Queue.

vector<int> bfsOfGraph(int V, vector<int> adj[]) {

    vector<int> answer;

    vector<bool> visited(V, false);

    queue<int> bfs;
    bfs.push(0);
    visited[0] = true;

    while (!bfs.empty()) {

        int sze = bfs.size();

        for (int i = 0; i < sze; i++) {

            int node = bfs.front();
            answer.push_back(node);
            bfs.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int child = adj[node][j];
                if (visited[child] == false) {
                    bfs.push(child);
                    visited[child] = true;
                }
            }

        }

    }

    return answer;

}
