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
    void dfs(TreeNode* root, bool& ans, long long& prev){
        if(!root) return;
        
        dfs(root->left, ans, prev);
        if(root->val <= prev) {
            //cout<<"here";
            ans=false;
            //return;
        }
        prev = root->val;
        dfs(root->right, ans, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        bool ans=true;
        long long prev = LONG_MIN;
        dfs(root, ans, prev);
        return ans;
    }
};