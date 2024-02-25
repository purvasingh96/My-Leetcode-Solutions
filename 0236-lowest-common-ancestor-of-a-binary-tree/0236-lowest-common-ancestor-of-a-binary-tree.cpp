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
private:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        auto left = lca(root->left, p, q);
        auto right = lca(root->right, p, q);
        
        if(left && right){
            return root;
        }
        
        if(left){
            return left;
        }
        
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};