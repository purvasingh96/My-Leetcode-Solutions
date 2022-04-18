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
    int kthSmallest(TreeNode* root, int k) {
        
        /*
        1.inorder : 
        2. return kth element
        */
        
        stack<TreeNode*> st;
        
        while(true) {
            while(root) {
                st.push(root);
                root=root->left;
            }
            
            root=st.top();
            st.pop();
            
            if(--k == 0) return root->val;
            
            root = root->right;
        }
        
    }
};