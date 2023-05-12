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
    int temp;
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int r=0, l=0;
        if(root->right) {
            r = dfs(root->right);
            
            // root->val += r;
            // temp = root->val;
            }
            root->val += temp;
         temp = root->val;
        if(root->left){
            
            l = dfs(root->left);
        } 
        
       
        return temp;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* ans = root;
        temp=0;
        dfs(root);
        return ans;
    }
};