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
    int dfs(TreeNode* root, int& global_max){
        if(!root) return 0;
        //if(!root->left && !root->right) return root->val;
        
        int left = max(dfs(root->left, global_max), 0);
        int right = max(dfs(root->right, global_max), 0);
        
        int path_without_main_root = root->val + left + right;
        int path_with_main_root = root->val + max(left, right);
        
        global_max = max(global_max, max(path_without_main_root, 
                                        path_with_main_root));
        
        return path_with_main_root;
        
        
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int global_max = INT_MIN;
        dfs(root, global_max);
        return global_max;
    }
};