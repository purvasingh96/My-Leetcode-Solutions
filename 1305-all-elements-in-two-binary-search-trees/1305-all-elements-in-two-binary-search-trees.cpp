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
    void pushLeft(stack<TreeNode*>& st, TreeNode* root) {
        while(root!=NULL) {
            st.push(root);
            root=root->left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> res;
        
        pushLeft(s1, root1);
        pushLeft(s2, root2);
        
        while(!s1.empty() || !s2.empty()) {
            stack<TreeNode*>& s = s1.empty()?s2 : s2.empty() ?  s1 : s1.top()->val < s2.top()->val ? s1:s2;
            
            TreeNode* n = s.top();
            s.pop();
            res.push_back(n->val);
            pushLeft(s, n->right);
            
        }
        
        return res;
        
    }
};