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
    void lca(Node* p, unordered_map<Node*, bool>& visited){
       if(p==NULL){
           return;
       }
        visited[p] = true;
        lca(p->parent, visited);
    }
    Node* check(Node* q, unordered_map<Node*, bool>& visited){
        if(!q){
            return NULL;
        }
        if(visited[q] == true){
            return q;
        }
        return check(q->parent, visited);
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*, bool> visited;
        lca(p, visited);
        return check(q, visited);
    }
};