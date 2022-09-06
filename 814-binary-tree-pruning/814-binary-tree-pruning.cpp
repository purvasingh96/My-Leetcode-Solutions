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
   TreeNode* dfs(TreeNode* root){
        if(!root) return NULL;
        
        
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        
        if(root->val == 0 && root->left==NULL && root->right==NULL){
            return NULL;
        }
        
        return root;
        
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        return dfs(root);
    }
};