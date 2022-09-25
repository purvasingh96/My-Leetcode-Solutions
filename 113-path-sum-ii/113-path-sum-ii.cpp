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
    void dfs(TreeNode* root, int target, vector<int> temp, vector<vector<int>>& res) {
        if(!root) return;
        
        target -= root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(target == 0) {
                res.push_back(temp);
                temp.clear();
            }
            return;
        }
        
        if(root->left) dfs(root->left, target, temp, res);
        if(root->right) dfs(root->right, target, temp, res);
        
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        
        dfs(root, target, temp, res);
        
        return res;
    }
};