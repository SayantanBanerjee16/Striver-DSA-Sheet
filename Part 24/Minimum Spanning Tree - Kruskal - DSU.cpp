// PROBLEM :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

// GFG | MEDIUM | MST -> KRUSKAL -> using DSU

// T.C. O(ElogV) S.C. O(E + V)

// Logic is :- Use a DSU -> Size N -> representing N nodes.
// First sort all edges with increasing weight.
// Now traverse in the edges, and use a edge when both nodes belong to different component.
// If they belong to different component, merge those nodes, and ADD the edge weight to final ans (mstWeight).

struct UnionFind {
	int n;
	vector<int> rank;
	vector<int> parent;
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

struct Edge{
    int u;
    int v;
    int wt;
};

bool compareEdges(Edge edge1, Edge edge2)
{
    return (edge1.wt < edge2.wt);
}

class Solution
{
    public:

    int spanningTree(int N, vector<vector<int>> adj[])
    {
        vector<Edge> edges;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                int v = adj[i][j][0];
                int wt = adj[i][j][1];
                struct Edge curEdge = {i, v, wt};
                edges.push_back(curEdge);
            }
        }
        
        sort(edges.begin(), edges.end(), compareEdges);
        
        UnionFind* uf = new UnionFind(N);
        
        int mstWeight = 0;
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int wt = edges[i].wt;
            
            if(uf->get(u) != uf->get(v)){
                mstWeight += wt;
                uf->merge(u, v);
            }
        }
        
        return mstWeight;
    }
};