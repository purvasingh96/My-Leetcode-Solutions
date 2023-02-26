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
    
    // O(N), O(1)
    vector<int> morris(TreeNode* root){
       TreeNode* curr = root;
        vector<int> res;
        
        while(curr){
            if(!curr->left){
                res.push_back(curr->val);
                curr = curr->right;
            } else{
                TreeNode* pred = predecessor(curr);
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                } else{
                    pred->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }   
            }
        }
        
        return res;
    }
    
    // O(N), O(N)
    vector<int> iterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        
        TreeNode* curr = root;
        
        while(true){
            
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            
            if(!st.empty()){
                curr = st.top(); st.pop();
                res.push_back(curr->val);
            } else break;
            
            if(curr) curr = curr->right;
        }
        
       
        
        return res;
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root){
        return morris(root);
    }
     
    
};