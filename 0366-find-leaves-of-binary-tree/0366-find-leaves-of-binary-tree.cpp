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
private:
    int dfs(TreeNode* root, vector<vector<int>>& res){
        if(!root->left && !root->right) {
            res[0].push_back(root->val);   
            return 0;
        }
        
        int left = 0, right=0;
        if(root->left) left = dfs(root->left, res);
        if(root->right) right=dfs(root->right, res);
        int idx = max(left,right)+1;
        res[idx].push_back(root->val);
        return idx;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res(101);
        dfs(root, res);
        vector<vector<int>> ans;
        for(auto x:res){
            if(x.size()!=0) ans.push_back(x);
        }
        return ans;
    }
};