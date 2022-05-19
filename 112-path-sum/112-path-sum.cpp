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
    void dfs(TreeNode* root, int target, int cursum, bool& ans) {
        if(!root) return;
        if(cursum==INT_MAX) cursum=0;
        cursum+= root->val;
        
        if(cursum==target && !root->left && !root->right){ 
            ans=true;
            return;
        }
        
        
        
        
        
        
        
        dfs(root->left, target, cursum, ans);
        dfs(root->right, target, cursum, ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        bool ans = false;
        dfs(root, targetSum, INT_MAX, ans);
        return ans;
    }
};