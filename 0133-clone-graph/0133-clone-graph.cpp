class Solution {
private:
   
    Node* dfs(Node* parent, unordered_map<Node*, bool>& visited, unordered_map<Node*, Node*>& m){
        if(m.find(parent)!=m.end()) return m[parent];
        m[parent] = new Node(parent->val);
        
        for(auto child:parent->neighbors){
            if(!visited[child]){
                visited[child] = true;
                m[parent]->neighbors.push_back(dfs(child, visited, m));
            } else {
               m[parent]->neighbors.push_back(m[child]);
            }
        }
        
        return m[parent];
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> m;
        unordered_map<Node*, bool> visited;
        visited[node] = true;
        return dfs(node, visited, m);
        
    }
};