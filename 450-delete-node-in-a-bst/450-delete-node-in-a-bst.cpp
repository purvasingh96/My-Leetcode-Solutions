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
    int successor(TreeNode* root){
        TreeNode* curr = root->right;
        while(curr->left) curr=curr->left;
        return curr->val;
    }
    
    int predecessor(TreeNode* root){
        TreeNode* curr = root->left;
        while(curr->right) curr=curr->right;
        return curr->val;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return root;
        
        if(root->val > key) root->left = deleteNode(root->left, key);
        
        else if(root->val < key) root->right = deleteNode(root->right, key);
        
        else{
            
            if(!root->left && !root->right){
                root=NULL;
            } else if(root->right){
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
            
            
        }
        
        return root;
        
    }
};