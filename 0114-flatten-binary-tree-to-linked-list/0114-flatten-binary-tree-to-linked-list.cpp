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
    TreeNode* pred(TreeNode* root){
        TreeNode* curr = root->left;
        while(curr->right){
            curr = curr->right;
        }
        return curr;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while(curr){
            TreeNode* tempRight = curr->right;
               if(curr->left){
                    TreeNode* pre = pred(curr);
                    pre->right=tempRight;
                   curr->right = curr->left;
                   curr->left = NULL;
                } 
            curr = curr->right;
        }
        
        
    }
};