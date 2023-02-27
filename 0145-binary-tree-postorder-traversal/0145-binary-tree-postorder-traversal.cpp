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
        TreeNode* pred = root->right;
        while(pred->left && pred->left!=root){
            pred=pred->left;
        }
        return pred;
    }
    
    vector<int> morris(TreeNode* root){
       vector<int> res;
        TreeNode* curr = root;
        
        while(curr){
            if(!curr->right){
                res.push_back(curr->val);
                curr=curr->left;
            } else{
                
                TreeNode* pred = predecessor(curr);
                
                if(pred->left==NULL){
                    res.push_back(curr->val);
                    pred->left=curr;
                    curr=curr->right;
                } else{
                    pred->left=NULL;
                    
                    curr=curr->left;
                }
                
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return morris(root);
    }
};