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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = new TreeNode(0, NULL, root);
        TreeNode* ans = prev;
        TreeNode* next;
        TreeNode* curr = root;
        
        while(curr){
            
            if(curr->left) {
                
                TreeNode* temp = curr->left;
                while(temp->right!=NULL) temp=temp->right;
                
                TreeNode* next = curr->left;
                temp->right=curr;
                curr->left=NULL;
                prev->right=next;
                curr=prev->right;
            }else{
                prev=prev->right;
                curr=curr->right;
            }
            
        }
        
        return ans->right;
    }
};