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
    int sum=0;
public:
    TreeNode* helper(TreeNode* root){
        if(root) {
            helper(root->right);
            sum += root->val;
            root->val = sum;
            helper(root->left);
        }
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        
        return helper(root);
    }
};