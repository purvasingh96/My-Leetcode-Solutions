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
    TreeNode* predecessor(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred && pred->right){
            pred=pred->right;
        }
        return pred;
    }
   
    
    TreeNode* deleteVal(TreeNode* root, int key){
        if(root){
           if(root->val > key){
            root->left= deleteVal(root->left, key);
        } else if(root->val < key){
            root->right= deleteVal(root->right, key);
        } else{
            if(!root->left && !root->right) return NULL;
            else if(!root->right || !root->left) {
                return root->right?root->right:root->left;
            } else{
                auto pred = predecessor(root);
                root->val=pred->val;
                root->left = deleteVal(root->left, root->val);
            }
        } 
        }
        
        return root;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        return deleteVal(root, key);
        
        
        
    }
};