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
    int helper(TreeNode* root, int& global_max) {
        
        if(!root) return 0;
        
        if(!root->left && !root->right) return 1;
        
        int left = helper(root->left, global_max);
        int right = helper(root->right, global_max);
        
        int m1 = max(max(left, right), left+right);
        global_max = max(global_max, m1);
        
        return 1+max(left, right);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int global_max=0;
         helper(root, global_max);
        return global_max;
    }
};