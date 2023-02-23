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
    int dfs(TreeNode* root, bool& ans){
            if(!root) return 0;
            int left=0, right=0;
            if(root->left) left = dfs(root->left, ans);
            if(root->right) right = dfs(root->right, ans);
            if(abs(left-right) > 1) {
                //cout<<"yes";
                ans=0;
                return 0;
            }
        return 1+max(left, right);
    
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans=1;
        dfs(root, ans);
        return ans;
    }
};