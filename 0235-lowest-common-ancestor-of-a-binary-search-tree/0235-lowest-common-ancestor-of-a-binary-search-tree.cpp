/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }
        
        if(root == p || root == q){
            return root;
        }
        
        auto l = dfs(root->left, p, q);
        auto r = dfs(root->right, p, q);
        
        if(l && r){
            return root;
        }
        
        return l ? l : r;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};