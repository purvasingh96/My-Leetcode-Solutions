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
        TreeNode* curr = root->left;
        while(curr->right){
            curr = curr->right;
        }
        return curr;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else if(root->val < key){
            root->right = deleteNode(root->right, key);
        } else{
            // equal;
            if(!root->left && !root->right) return NULL;
            else if(!root->left || !root->right){
                if(root->left) return root->left;
                return root->right; 
            } else{
                TreeNode* pred = predecessor(root);
                auto temp = root->val;
                root->val=pred->val;
                pred->val = temp;
                root->left = deleteNode(root->left, temp);
            }
        }
        return root;
    }
};