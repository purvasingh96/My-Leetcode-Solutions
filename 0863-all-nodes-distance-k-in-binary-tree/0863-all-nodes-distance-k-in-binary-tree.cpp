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
            m[root].push_back(root->left);
            m[root->left].push_back(root);
            dfs(root->left, m);
        }
        
        if(root->right){
            m[root].push_back(root->right);
            m[root->right].push_back(root);
            dfs(root->right, m);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> m;
        unordered_map<TreeNode*, bool> visited;
        vector<int> ans;
        
        if(k==0){
            return {target->val};
        }
        
        dfs(root, m);
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto f = q.front();
                q.pop();
                
                for(auto c:m[f]){
                    if(visited[c] == false){
                        visited[c] = true;
                        q.push(c);
                    }
                }
            }
            k--;
            if(k==0){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
        }
        
        return ans;
        
    }
};