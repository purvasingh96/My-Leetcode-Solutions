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
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*, bool> visited;
        
        while(p && q){
            if(p == q) return p;
            if(visited[p] == true) return p;
            if(visited[q] == true) return q;
            
            visited[p] = true;
            visited[q] = true;
            
            p = p->parent;
            q = q->parent;
        }
        
        while(p){
            if(visited[p] == true) return p;
            visited[p] = true;
            p = p->parent;
        }
        
        while(q){
            if(visited[q] == true) return q;
            visited[q] = true;
            q = q->parent;
        }        
        
        return NULL;
    }
};