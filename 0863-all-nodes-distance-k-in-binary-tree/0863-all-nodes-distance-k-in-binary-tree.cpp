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
    void dfs(TreeNode* root, TreeNode* parent, map<TreeNode*, vector<TreeNode*>>& m){
        if(!root) {
            return;
        }
        
        if(parent){
            m[root].push_back(parent);    
        }
        
        if(root->left){
            m[root].push_back(root->left);
            dfs(root->left, root, m);
        }
        if(root->right){
            m[root].push_back(root->right);
            dfs(root->right, root, m);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, vector<TreeNode*>> m;
        dfs(root, NULL, m);
        vector<int> res;
        queue<TreeNode*> q;
        q.push(target);
        int d=0;
        map<TreeNode*, bool> visited;
        visited[target]=true;
        //cout<<"m.size():: "<<m.size();
        
        
        while(q.size()!=0){
            int sz = q.size();
            while(sz--){
                auto f =q.front();
                q.pop();
                if(d==k){
                    res.push_back(f->val);
                    
                }
                else {
                   if(m[f].size()!=0){
                        for(auto x:m[f]){
                            if(visited[x]==false){
                                visited[x] = true;
                                q.push(x);
                            }
                            
                        }
                    } 
                }
                
            }
            d+=1;
        }
        
        return res;
    }
};