/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_map<TreeNode*, bool>& visited){
        if(!root) return;
        visited[root] =false;
        if(parent->val!=-1){
            adj[root].push_back(parent);
        }
        if(root->left) {
            adj[root].push_back(root->left);
            dfs(root->left, root, adj, visited);
        }
        if(root->right){
            adj[root].push_back(root->right);
            dfs(root->right, root, adj, visited);
        }
    }
    
    vector<int> bfs( unordered_map<TreeNode*, vector<TreeNode*>>& adj, TreeNode* target, int k, unordered_map<TreeNode*, bool> visited){
        vector<int> res;
        queue<TreeNode*> q;
        q.push(target);
        
        visited[target]=true;
        int level=0;
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                auto f = q.front();
                q.pop();
                if(level == k){
                    res.push_back(f->val);
                }
                for(auto x:adj[f]){
                    if(visited[x]==false){
                        visited[x]=true;
                        q.push(x);
                    }
                        
                }
            }
            level+=1;
        }
        
        return res;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        TreeNode* parent = new TreeNode(-1);
        vector<int> res;
        unordered_map<TreeNode*, bool> visited;
        dfs(root, parent, adj, visited);
        // for(auto x:adj){
        //     cout<<x.first->val<<" : ";
        //     for(auto y:x.second){
        //         cout<<y->val<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return bfs(adj, target, k, visited);
    }
};