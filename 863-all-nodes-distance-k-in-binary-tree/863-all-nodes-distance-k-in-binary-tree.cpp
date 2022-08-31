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
    vector<int> bfs(TreeNode* target, int k, map<TreeNode*, unordered_set<TreeNode*>>& m){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;
        vector<int> res;
        
        while(k--){
            int n = q.size();
            
            while(n--){
                
                auto f = q.front();
                q.pop();
                visited[f] = true;
                
                for(auto c:m[f]) {
                    if(!visited[c]) q.push(c);
                }
                
            }
            
        }
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            res.push_back(f->val);
            
        }
        
        return res;
        
    }
    
    
    void fillMap(TreeNode* root, map<TreeNode*, unordered_set<TreeNode*>>& m){
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int n =q.size();
            for(int i=0;i<n;i++){
                
                auto f = q.front();
                q.pop();
                
                if(f->left) {
                    q.push(f->left);
                    m[f].insert(f->left);
                    m[f->left].insert(f);
                }
                
                if(f->right){
                    q.push(f->right);
                    m[f].insert(f->right);
                    m[f->right].insert(f);
                }
                
            }
        }
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, unordered_set<TreeNode*>> m;
        fillMap(root, m);
        auto res = bfs(target, k, m);
        
        return res;
    }
};