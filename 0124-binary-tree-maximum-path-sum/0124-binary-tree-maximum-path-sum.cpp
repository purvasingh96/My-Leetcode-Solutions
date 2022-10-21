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
    int dfs(TreeNode* root, int& global) {
        if(!root) return 0;
        int left = dfs(root->left, global);
        int right = dfs(root->right, global);
        
        
        int sum1 = root->val + max(left, right);
        sum1 = max(sum1, root->val);
        int sum2 = root->val + left + right;
        
        global = max(global, max(sum1, sum2));
        
        return sum1;
        
    }
public:
    
    int maxPathSum(TreeNode* root) {
        int global = root->val;
        dfs(root, global);
        return global;
    }
};