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
    bool find(TreeNode* root, int p, int q) {
        if(!root) return false;
        if(root->val == p || root->val == q) return true;
        
        return (find(root->left, p, q) || find(root->right, p, q));
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val == p->val || root->val ==  q->val) return root;
        
        bool left = find(root->left, p->val, q->val);
        bool right = find(root->right, p->val, q->val);
        
        if(left && right) return root;
        
        else if(left && !right) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
       
        return lowestCommonAncestor(root->right, p, q);
        
        
        
    }
};