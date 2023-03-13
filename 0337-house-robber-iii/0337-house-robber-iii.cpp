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
    map<pair<TreeNode*, int>, int> dp;
    int dfs(TreeNode* root, int parentRobbed){
        if(!root) return 0;
        
        if(dp.find({root, parentRobbed}) != dp.end()) return dp[{root, parentRobbed}];
        
        int rob=-1, notRob=-1;
        if(!parentRobbed){
           rob = root->val + dfs(root->left, 1) + dfs(root->right, 1); 
        }
        notRob = dfs(root->left, 0) + dfs(root->right, 0);
        return dp[{root, parentRobbed}] = max(rob, notRob);
        
    }
public:
    int rob(TreeNode* root) {
        return dfs(root, 0);
    }
};