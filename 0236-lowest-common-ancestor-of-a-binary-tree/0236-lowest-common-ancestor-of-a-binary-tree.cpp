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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root == p) return p;
        if(root == q) return q;
        
        auto foundP = dfs(root->left, p, q);
        auto foundQ = dfs(root->right, p, q);
        
        if(foundP && foundQ){
            return root;
        }
        
        if(foundP && !foundQ) return foundP;
        return foundQ;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};