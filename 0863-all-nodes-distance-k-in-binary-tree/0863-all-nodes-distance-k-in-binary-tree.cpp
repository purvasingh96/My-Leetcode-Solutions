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
    void dfs(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& m){
        if(!root){
            return;
        }
        
        if(root->left){
            m[root->left].push_back(root);
            m[root].push_back(root->left);
            dfs(root->left, m);
        }
        
        if(root->right){
            m[root->right].push_back(root);
            m[root].push_back(root->right);
            dfs(root->right, m);
        }
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> m;
        dfs(root, m);
        queue<TreeNode*> q;
        q.push(target);
        vector<int> ans;
        unordered_map<TreeNode*, bool> visited;
        visited[target]=true;
        
        while(!q.empty() && k--){
            int sz= q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                for(auto x:m[f]){
                    if(!visited[x]){
                        visited[x]=true;
                        q.push(x);
                    }
                }
            }
            if(k==0){
               break; 
            }
        }
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            ans.push_back(f->val);
        }
        
        return ans;
        
    }
};