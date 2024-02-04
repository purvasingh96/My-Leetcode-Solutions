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
    void dfs(TreeNode* root, int low, int high, int& total){
        if(!root) return;
        dfs(root->left, low, high, total);
        if(root->val >= low && root->val <=high){
            total += root->val;
        }
        dfs(root->right, low, high, total);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // inorder and add
        int total=0;
        dfs(root, low, high, total);
        return total;
    }
};