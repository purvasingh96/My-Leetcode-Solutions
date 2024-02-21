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
    int dfs(TreeNode* root, int& ans){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        int ans1 = l+r; // include root
        int ans2  = max(l, r); // don't include root
        ans = max(ans, max(ans1, ans2));
        return 1 + ans2;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};