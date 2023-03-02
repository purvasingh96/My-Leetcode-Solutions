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
    int dfs(TreeNode* root, int& global){
        if(!root) return 0;
        
        int l = max(dfs(root->left, global),0);
        int r = max(dfs(root->right, global),0);
        
        int s1 = root->val + l + r;
        
        int s2= root->val + max(l, r);
        
        global = max({root->val, global, s1, s2});
        
        return s2;
    }
public:
    int maxPathSum(TreeNode* root) {
        int global=INT_MIN;
        dfs(root, global);
        return global;
    }
};