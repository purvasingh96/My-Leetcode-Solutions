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
    int ans=0;
    int helper(TreeNode* root){
        // no root
        if(root==NULL) return 0;
        
        // leaf node
        if(root->left == NULL && root->right == NULL) return root->val;
        
        int l = helper(root->left);
        int r = helper(root->right);
        ans += abs(l-r);
        
        return root->val + l + r;
        
    }
public:
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};