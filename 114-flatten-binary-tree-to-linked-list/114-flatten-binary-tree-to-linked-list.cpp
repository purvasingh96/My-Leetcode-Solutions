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
        if(!root->left && !root->right) return root;
        
        TreeNode* x = dfs(root->right);
        TreeNode* y = dfs(root->left);
        
        if(y){
            while(y->right) y=y->right;
            y->right=x;
            TreeNode* temp = root->left;
            root->left=NULL;
            root->right = temp;
        }
        
        return root;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);   
    }
};