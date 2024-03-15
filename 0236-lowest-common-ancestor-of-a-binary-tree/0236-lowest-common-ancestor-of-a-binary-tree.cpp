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
    bool fp, fq;
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }
        
        auto left = lca(root->left, p, q);
        auto right = lca(root->right, p, q);
        
        if(root==p){
            fp=true;
            return root;
        }
        
        if(root==q){
            fq=true;
            return root;
        }
        
        if(left && right){
            return root;
        }
        
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fp=false, fq=false;
        auto ans = lca(root, p, q);
        if(fp && fq){
            return ans;
        }
            
        return NULL;
    }
};