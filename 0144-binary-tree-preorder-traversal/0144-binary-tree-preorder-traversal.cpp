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
        while(pred->right && pred->right!=root){
            pred=pred->right;
        }
        return pred;
    }
    
    vector<int> morris(TreeNode* root){
        TreeNode* curr = root;
        vector<int> res;
        
        while(curr){
            
            if(!curr->left){
               res.push_back(curr->val);
                curr=curr->right;
            } else{
                TreeNode* pred = predecessor(curr);
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
    
    vector<int> iterative(TreeNode* root){
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* curr = st.top();st.pop();
            
            if(curr){
                res.push_back(curr->val);    
                st.push(curr->right);
                st.push(curr->left);
            }
        }
        
        return res;
        
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return iterative(root);
    }
};