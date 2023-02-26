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
};