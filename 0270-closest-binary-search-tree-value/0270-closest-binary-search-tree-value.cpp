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
    void dfs(TreeNode* root, double target, map<double, vector<int>>& res){
        if(!root) return;
        
        dfs(root->left, target, res);
        res[abs(target - root->val)].push_back(root->val);
        dfs(root->right, target, res);
    }
public:
    int closestValue(TreeNode* root, double target) {
        map<double, vector<int>> res;
        dfs(root, target, res);
        return res.begin()->second[0];
    }
};