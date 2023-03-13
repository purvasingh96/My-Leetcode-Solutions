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
        while(curr->right && curr->right!=root){
            curr = curr->right;
        }
        return curr;
    }
public:
    vector<int> morris(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        TreeNode* curr = root;
        
        while(curr){
            if(!curr->left){
                res.push_back(curr->val);
                curr=curr->right;
            } else{
                auto pred = predecessor(curr);
                if(pred->right==NULL){
                    res.push_back(curr->val);
                    pred->right=curr;
                    curr=curr->left;
                } else{
                    pred->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return res;
    }
        
    vector<int> preorderTraversal(TreeNode* root) {
        return morris(root);
    }
};