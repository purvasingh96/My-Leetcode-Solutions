/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string s_helper(Node* root){
        if(!root) return "";
        queue<Node*> q;
        q.push(root);
        string path = "";
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                if(f==NULL) {
                    path += "NULL#";
                    continue;
                } else {
                    path += to_string(f->val) + ":" + to_string(f->children.size()) + "#";
                }
                
                
                
                for(auto x:f->children){
                    q.push(x);
                }
                
            }
            
            
            
        }
        
        return path;
        
    }
    
    
    
    vector<pair<int, int>> split(string data){
        
        stringstream ss(data);
        string temp;
        
        vector<pair<int, int>> res;
        if(data.length()==0) return res;
        
        
        while(getline(ss, temp, '#')){
            int idx = temp.find_first_of(':');
            int node = stoi(temp.substr(0, idx));
            int sz = stoi(temp.substr(idx+1));
            
            res.push_back({node, sz});
        }
        
        return res;
    }
    
    
    
    
    string serialize(Node* root) {
        return s_helper(root);
    }

    
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        vector<pair<int, int>> res = split(data);
        if(res.size()==0) return NULL;
        
        
        queue<pair<Node*, int>> q;
        Node* root = new Node(res[0].first);
        
        q.push({root, res[0].second});
        int i=1;
        while(!q.empty()){
            
            auto f=q.front();
            q.pop();
            
            Node* node = f.first;
            int sz = f.second;
            
            while(sz--){
               Node* child = new Node(res[i].first);
               node->children.push_back(child);
                q.push({child, res[i].second});
                i+=1;
            }
            
            
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));