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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur_node = root;
        vector<int> inorder;
        
        while(cur_node) {
            
            if(cur_node->left) {
                
                TreeNode* pred = cur_node->left;
                
                while(pred->right!=NULL && pred->right!=cur_node){
                    pred=pred->right;
                }
                
                if(pred->right==NULL) {
                    pred->right=cur_node;
                    cur_node=cur_node->left;
                } else{
                    pred->right=NULL;
                    inorder.push_back(cur_node->val);
                    cur_node=cur_node->right;
                }
                
                
            } else {
                
                inorder.push_back(cur_node->val);
                cur_node=cur_node->right;
                
            }
            
        }
        
        return inorder;
        
    }
};