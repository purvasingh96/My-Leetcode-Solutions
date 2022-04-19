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
    void swap(TreeNode* a, TreeNode* b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* x= NULL;
        TreeNode* y=NULL;
        TreeNode* pred=NULL;
        
        while(!st.empty() || root!=NULL) {
            
            while(root!=NULL) {
                st.push(root);
                root=root->left;
            }
            
            root = st.top();
            st.pop();
            
            if(pred!=NULL && root->val < pred->val) {
                y=root;
                if(x==NULL) x=pred;
                else break;
                
            }
            
            pred=root;
            root=root->right;
            
        }
        
        swap(x, y);
        
    }
};