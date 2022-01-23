// PROBLEM :- https://leetcode.com/problems/clone-graph/

// LEETCODE | MEDIUM | DESIGN CLONE GRAPH

class Solution {
public:
    
    unordered_map<Node*,Node*> clones;
    
    Node* cloneGraph(Node* node) {
        
       if(node==NULL)
           return node;
        
        if(clones.find(node)!=clones.end()){
            return clones[node];
        }
        
        Node* newClone=new Node(node->val);
        clones[node]=newClone;
        
        for(Node* currN: node->neighbors){
            //pushing the neighbor(clone) of current node into the neighbour of clone of currNode.
            clones[node]->neighbors.push_back(cloneGraph(currN));
        }
        
        return newClone;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/