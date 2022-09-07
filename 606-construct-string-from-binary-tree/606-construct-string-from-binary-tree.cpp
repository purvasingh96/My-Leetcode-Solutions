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
    string dfs(TreeNode* root){
        if(!root) {
            return "";
        }
        
        if(!root->left && !root->right){
            return to_string(root->val);
        }
        
        if(!root->right) return to_string(root->val) + "(" + dfs(root->left) + ")";
        
        return to_string(root->val) + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
        
    }
public:
    string tree2str(TreeNode* root) {
        string val="";
        
        return dfs(root);
        
    }
};