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
private:
    string serializeHelper(Node* root){
        if(!root){
            return "";
        }
        
        if(root->children.size()==0){
            return "(" + to_string(root->val) + ")";
        }
        
        string children="";
        for(auto c:root->children){
            children += serializeHelper(c);    
        }
        
        return "(" + to_string(root->val) + children + ")";
    }
    
    Node* deserializeHelper(string s){
        s = s.substr(1);
        s.pop_back();
        stack<Node*> st;
        char op='(';
        
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int d=0;
                int j=i;
                
                while(j<s.length() && isdigit(s[j])){
                    d = d*10 + (s[j]-'0');
                    j+=1;
                }
                
                i=j-1;
                Node* node = new Node(d);
                
                if(st.empty()){
                    st.push(node);
                } else {
                    st.top()->children.push_back(node);
                    st.push(node);
                }
                
                d=0;
            } else {
                if(s[i] == ')') {
                    if(!st.empty()){
                        st.pop();
                    }
                }
            }
        }
        
        return st.top();
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root){
            return "";
        }
        return serializeHelper(root);
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.length() == 0){
            return NULL;
        }
        return deserializeHelper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));