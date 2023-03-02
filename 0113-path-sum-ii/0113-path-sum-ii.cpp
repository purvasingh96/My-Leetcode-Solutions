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
    void dfs(TreeNode* root, int& sum, int targetSum, vector<vector<int>>& res, vector<int>& temp){
    if(!root) return;
    
    sum += root->val;
    temp.push_back(root->val);
        
        // for(auto x:temp) cout<<x<<" ";
        // cout<<"\n";
        
    if(sum == targetSum && !root->left && !root->right){
        res.push_back(temp);
    }
        
    dfs(root->left, sum, targetSum, res, temp);
    dfs(root->right, sum, targetSum, res, temp);
    temp.pop_back();
    sum -= root->val;
    
}

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
    vector<int> temp;
        int sum=0;
    
    dfs(root, sum, targetSum, res, temp);
    
    return res;
    }
};