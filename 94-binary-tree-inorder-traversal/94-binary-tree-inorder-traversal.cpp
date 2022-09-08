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
        if(!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        
        
        unordered_map<TreeNode*, bool> seen;
        
        while(!st.empty()) {
            
            while(st.top()->left && seen.find(st.top()->left)==seen.end()){
                st.push(st.top()->left);
            }
            
            auto top = st.top();
            st.pop();
            res.push_back(top->val);
            seen[top] = true;
            
            if(top->right) st.push(top->right);
            
        }
            
        return res;
    }
};