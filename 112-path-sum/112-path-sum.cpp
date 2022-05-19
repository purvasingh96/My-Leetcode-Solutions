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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, targetSum});
        
        while(!st.empty()) {
            
            auto f = st.top();
            st.pop();
            TreeNode* node = f.first;
            int remain = f.second;
            
            if(node!=NULL) {
                remain -= node->val;
                if(!node->left && !node->right && remain == 0) {
                    return true;
                }
            
                st.push({node->left, remain});
                st.push({node->right, remain});
                
            }
            
            
        }
        
        return false;
        
    }
};