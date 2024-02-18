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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*, Node*> m;
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(node);
        visited[node] = true;
        
        while(q.size()!=0){
            
                auto f = q.front();
                q.pop();
                
                if(m.find(f)==m.end()){
                    m[f] = new Node(f->val);
                }
                
                for(auto c:f->neighbors){
                    if(m.find(c)==m.end()){
                        m[c] = new Node(c->val);
                    }
                    m[f]->neighbors.push_back(m[c]);
                    if(visited[c] == false){
                        visited[c] = true;
                        q.push(c);    
                    }
                    
                }
            
        }
        
        return m[node];
        
    }
};