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
    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if(!root) return 0;
        
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        
        int d = max(left, right);
            
        res[d].push_back(root->val);
        
        return d+1;
        
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res(100);
        int d = dfs(root, res);
        
        vector<vector<int>> subres(res.begin(), res.begin()+d);
        
        return subres;
    }
};