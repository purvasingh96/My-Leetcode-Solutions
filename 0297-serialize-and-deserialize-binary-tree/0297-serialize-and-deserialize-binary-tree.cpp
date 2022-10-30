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
public:
    
    string levelOrder(TreeNode* root){
        string path = "";
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                
            
            auto f = q.front();
            q.pop();
            
            if(f==NULL) path+="NULL#";
            else path += to_string(f->val)+"#";
            
            
            if(f) {
                q.push(f->left);
                q.push(f->right);
            }
        }
            
        }
        
        return path;
        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        return levelOrder(root);
    }
    
    TreeNode* helper(vector<int>& levels){
        
        for(auto x:levels) cout<<x<<" ";
        TreeNode* root= new TreeNode(levels[0]);
        
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            if(levels[i]!=INT_MAX){
                auto left = new TreeNode(levels[i]);
                node->left = left;
                q.push(left);
            }
            i+=1;
            if(levels[i]!=INT_MAX){
                auto right= new TreeNode(levels[i]);
                node->right = right;
                q.push(right);
            }
            i+=1;
            
        }
        
        return root;
            
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        vector<int> levels;
        stringstream ss(data);
        
        string temp;
        while(getline(ss, temp, '#')){
            if(temp == "NULL") levels.push_back(INT_MAX);
            else levels.push_back(stoi(temp));
        }
        
        return helper(levels);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));