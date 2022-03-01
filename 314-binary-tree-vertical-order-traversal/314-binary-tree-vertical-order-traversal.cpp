/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        
        
        map<int, vector<int>> m;
        vector<vector<int>> res;
        
        if(!root) return res;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        
        while(!q.empty()) {
            
            int s = q.size();
            
            for(int i=0;i<s;i++) {
                
                auto f = q.front();
                q.pop();
                
                
                TreeNode* node = f.first;
                int col = f.second;
                
                m[col].push_back(node->val);
                
                if(node->left) {
                    q.push({node->left, col-1});
                }
                
                if(node->right) {
                    q.push({node->right, col+1});
                }
                
                
            }
            
        }
        
        for(auto x:m) {
            res.push_back(x.second);
        }
        
        return res;
        
    }
};