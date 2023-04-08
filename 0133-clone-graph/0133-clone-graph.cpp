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

private:
    unordered_map<Node*, Node*> m;
    
    Node* dfs(Node* ogNode){
        if(!ogNode) return ogNode;
        
        if(m.find(ogNode)!=m.end()) return m[ogNode];
       
        Node* newNode = new Node(ogNode->val);
        m[ogNode] = newNode;
        
        for(auto child:ogNode->neighbors){
                Node* newChild = dfs(child);
                newNode->neighbors.push_back(newChild);
            
        }
        
        return newNode;
        
    }
    
   
    
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
        
    }
};