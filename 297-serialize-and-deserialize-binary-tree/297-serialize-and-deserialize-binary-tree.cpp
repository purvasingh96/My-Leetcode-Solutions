/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serialize_helper(TreeNode* root, string& s){
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) {
            s="NULL,";
            return;
        }
        
        s += to_string(root->val)+",";
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto f = q.front();
                q.pop();
                
                if(f->left){
                    s+= to_string(f->left->val) + ",";
                    q.push(f->left);
                } else {
                    s+= "NULL,";                    
                }
                
                if(f->right){
                    s+= to_string(f->right->val) + ",";
                    q.push(f->right);
                } else{
                    s+="NULL,";
                }
            }
        }
    }
    
    TreeNode* deserialize_helper(string s, vector<int> inorder){
        
       if(s=="NULL") {
           return NULL;
       }
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(inorder[0]);
        q.push(root);
        
        int idx=0;
        
        while(idx<inorder.size()){
            auto f = q.front();
            q.pop();
            
            idx+=1;
            
            
            if(idx<inorder.size() && inorder[idx]!=INT_MAX){
                f->left=new TreeNode(inorder[idx]);
                q.push(f->left);
            } 
            idx+=1;
            
            if(idx<inorder.size() && inorder[idx]!=INT_MAX){
                f->right = new TreeNode(inorder[idx]);
                q.push(f->right);
            }
        }
        return root;
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        serialize_helper(root, s);
        
        s = s.substr(0, s.length()-1);
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> inorder;
        stringstream ss(data);
        
        while(ss.good()){
            string word;
            getline(ss, word, ',');
            
            if(word=="NULL") inorder.push_back(INT_MAX);
            else inorder.push_back(stoi(word));
        }
        
        
        return deserialize_helper(data, inorder);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));