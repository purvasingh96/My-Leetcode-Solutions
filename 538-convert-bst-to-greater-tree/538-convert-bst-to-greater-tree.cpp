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
    TreeNode* getSuccessor(TreeNode* root) {
        TreeNode* succ = root->right;
        while(succ->left!=NULL && succ->left!=root) {
            succ = succ->left;
        }
        return succ;
    }
public:
    
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* curr = root;
        int sum =0;
        
        while(curr!=NULL) {
            
            if(curr->right == NULL) {
                
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
                
            } else {
                
                TreeNode* succ = getSuccessor(curr);
                
                if(succ->left==NULL) {
                    succ->left = curr;
                    curr = curr->right;
                } else {
                    succ->left=NULL;
                    sum += curr->val;
                    curr->val = sum;
                    curr = curr->left;
                }
                
            }
            
        }
        
        return root;
    }
};