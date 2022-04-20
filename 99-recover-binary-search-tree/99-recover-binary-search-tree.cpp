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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        
        TreeNode* first=NULL; 
        TreeNode* second=NULL;
        TreeNode* prev=new TreeNode(INT_MIN);
        
        while(!st.empty() || root!=NULL){
            
            while(root!=NULL) {
                st.push(root);
                root=root->left;
            }
            
            root = st.top();
            st.pop();
            
            if(first==NULL && prev->val > root->val){
                first = prev;
            }            
            
            if(first!=NULL && prev->val > root->val) {
                second=root;
            }
            
            prev=root;
            root=root->right;
        }
       
        int t = first->val;
        first->val = second->val;
        second->val=t;
        
    }
};