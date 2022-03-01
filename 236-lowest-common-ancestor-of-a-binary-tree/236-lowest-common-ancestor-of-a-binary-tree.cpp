/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        map<TreeNode*, TreeNode*> parent;
        
        parent[root]=NULL;
        st.push(root);
        
        while((parent.find(p)==parent.end()) || parent.find(q)==parent.end()) {
            
            TreeNode* top = st.top();
            st.pop();
            
            if(top->left) {
                
                parent[top->left] = top;
                st.push(top->left);
            }
            
            if(top->right) {
                
                parent[top->right] = top;
                st.push(top->right);
                
            }
            
        }
        
        cout<<parent.size();
        
        set<TreeNode*> p_ancestors;
        
        while(p!=NULL) {
            p_ancestors.insert(p);
            p = parent[p];
        }
        
        while(p_ancestors.find(q)==p_ancestors.end()) {
            q = parent[q];
        }
        
        return q;
        
    }
};