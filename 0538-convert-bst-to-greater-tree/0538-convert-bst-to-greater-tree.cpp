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
    void dfs(TreeNode* root, int& temp){
        if(!root) return;
        
        if(root->right) dfs(root->right, temp);
        
        root->val += temp;
        temp = root->val;
        
        if(root->left) dfs(root->left, temp);
       
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* ans = root;
        int temp=0;
        dfs(root, temp);
        return ans;
    }
};