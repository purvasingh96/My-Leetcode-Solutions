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
    int ans;
public:
    bool dfs(TreeNode* root) {
        if(!root) return true;
        
        
        bool leftinfo = dfs(root->left);
        bool rightinfo = dfs(root->right);
    
        
        if(leftinfo && rightinfo) {
            // is univalue
            if(root->left) {
                if(root->val != root->left->val) {
                    return false;
                } 
            }
                
              if(root->right) {
                 if(root->val != root->right->val) {
                     return false;
                 }
            }
                
            ans+=1;
                return true;
                
            }
     
        
        return false;
        
        
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        ans=0;
        dfs(root);
        return ans;
        
    }
};