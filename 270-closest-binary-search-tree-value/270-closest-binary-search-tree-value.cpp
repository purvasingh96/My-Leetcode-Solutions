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
    void dfs(TreeNode* root, double target, int& close_node){
        if(!root) return;
        if(root){
            
            int val = root->val;
            close_node = abs(target - val) > abs(target - close_node) ? close_node:val;
            
            if(root->val > target){
                dfs(root->left, target, close_node);
            } else{
                dfs(root->right, target, close_node);
            }
            
        }
        
    }
public:
    int closestValue(TreeNode* root, double target) {
        int close_node=root->val;
        dfs(root, target, close_node);
        return close_node;
    }
};