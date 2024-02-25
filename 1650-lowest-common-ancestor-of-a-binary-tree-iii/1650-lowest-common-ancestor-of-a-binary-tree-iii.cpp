/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
private:
    void dfs(Node* p, unordered_map<Node*, bool>& visited){
        if(!p){
            return;
        }
        
        visited[p] = true;
        dfs(p->parent, visited);
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*,bool> visited;
        dfs(p, visited);
        
        while(q){
            if(visited[q] == true){
                return q;
            }
            q = q->parent;
        }
        
        return p;
    }
};