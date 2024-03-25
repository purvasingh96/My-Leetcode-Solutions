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
        map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        map<Node*, bool> visited;
        visited[node] = true;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(m.find(f)==m.end()){
                    m[f] = new Node(f->val);
                }
                
                for(auto x:f->neighbors){
                    if(m.find(x) == m.end()){
                            m[x] = new Node(x->val);
                        }
                    m[f]->neighbors.push_back(m[x]);
                    if(visited[x] == false){
                        visited[x] = true;
                        q.push(x);
                        
                    }
                }
                
            }
        }
        
        return m[node];
        
    }
};