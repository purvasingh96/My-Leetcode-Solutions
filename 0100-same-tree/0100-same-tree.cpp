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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        st.push(p);
        st.push(q);
        
        while(!st.empty()){
            auto a = st.top();
            st.pop();
            auto b = st.top();
            st.pop();
            
            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val!=b->val) return false;
            
            st.push(a->left);
            st.push(b->left);
            st.push(a->right);
            st.push(b->right);
        }
        
        return true;
    }
};