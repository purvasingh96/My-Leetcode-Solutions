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
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* left = root;
        TreeNode* right = root;
        int ht=0;
        
        while(right!=NULL){
            right = right->right;
            left = left->left;
            ht+=1;
        }
        
        if(left==NULL){
            // complete binary tree
            return pow(2, ht) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};