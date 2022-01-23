// PROBLEM :- https://leetcode.com/problems/is-graph-bipartite/

// LEETCODE | MEDIUM | BIPARTITE GRAPH

// Solution L- T.C. O(N + E) S.C. O(N) -> DFS

// Lets have a vector for color of all nodes.
// Color -1 -> Not coloured , i.e, not visited
// Color 0 and Color 1 -> Two colours to represent Bipartite

// Lets color each of them. If we found a child node which is not coloured, 
// color it with opposite color of current node color.
// If child node is already coloured and SAME that of current node colour, the given graph is NOT BIPARTITE.

// FURTHER INFO :- If we need to segregate nodes finally, 
// we can easily do by combining all nodes of Color 0 in first set,
// and combining all nodes of Color 1 in other set.

class Solution {
public:
    
    bool notBipartiteDFS(int node, int cur_color, vector<vector<int>>& adj, vector<int> &color){
        
        color[node] = cur_color;
        
        for(int i = 0 ; i < adj[node].size() ; i++){
            int child = adj[node][i];
            if(color[child] == -1){
                if(cur_color == 1){
                    if(notBipartiteDFS(child, 0, adj, color))
                        return true;
                }else{
                    if(notBipartiteDFS(child, 1, adj, color))
                        return true;
                }
            }else if(cur_color == color[child]){
                return true;
            }
        }
        
        return false;
    }
    
    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int N = adj.size();
        vector<int> color(N, -1);
        
        for(int i = 0 ; i < N ; i++){
            if(color[i] == -1){
                if(notBipartiteDFS(i, 0, adj, color))
                    return false;
            }
        }
        
        return true;
    }
};

// Solution 2- T.C. O(N + E) S.C. O(N) -> BFS

// Idea is same as that of DFS but here we would be using Queue (Iterative in place of Recursion).

class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& adj) {
        
        int N = adj.size();
        vector<int> color(N, -1);
        
        queue<int> bfs;
        
        for(int i = 0 ; i < N ; i++){
            if(color[i] == -1){
                bfs.push(i);
                color[i] = 0;
                
                while(!bfs.empty()){
                    
                    int node = bfs.front();
                    bfs.pop();
                    
                    for(int i = 0 ; i < adj[node].size() ; i++){
                        int child = adj[node][i];
                        
                        if(color[child] == -1){
                            if(color[node] == 0){
                                color[child] = 1;
                            }else{
                                color[child] = 0;
                            }
                            bfs.push(child);
                        }else{
                            if(color[child] == color[node])
                                return false;
                        }
                        
                    }  
                    
                }
                
            }
        }
        
        return true;
    }
};