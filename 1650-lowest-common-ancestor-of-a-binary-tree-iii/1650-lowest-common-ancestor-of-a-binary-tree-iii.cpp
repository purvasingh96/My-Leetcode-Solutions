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
        // parent is ancesor of node
        vector<Node*> ancestor_p;
        
        Node* parent_p = p;
        
        while(parent_p!=NULL) {
            ancestor_p.push_back(parent_p);
            parent_p = parent_p->parent;
        }
        
        Node* parent_q = q;
        
        while(find(ancestor_p.begin(), ancestor_p.end(), parent_q) == ancestor_p.end()) {
            parent_q = parent_q->parent;
        }
        return parent_q;
    }
};