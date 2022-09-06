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
    TreeNode* ans;
    pair<TreeNode*, int> dfs(TreeNode* root){
        if(!root) return {NULL, 0};
        
        if(!root->left && !root->right){
            if(root->val == 0) {
                return {NULL, 0};
            }
            return {root, 1};
        }
        
        auto left = dfs(root->left);
        root->left = left.first;
        auto right = dfs(root->right);
        root->right = right.first;
        
        if((root->val || left.second || right.second) == 0){
            return {NULL, 0};
        }
        
        return {root, 1};
        
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        auto res = dfs(root);
        return res.first;
    }
};