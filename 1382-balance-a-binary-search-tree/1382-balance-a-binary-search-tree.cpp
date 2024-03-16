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
private:
    void inorder(TreeNode* root, vector<TreeNode*>& res){
        if(!root){
            return;
        }
        inorder(root->left, res);
        res.push_back(root);
        inorder(root->right, res);
    }
    
    TreeNode* dfs(int l, int r, vector<TreeNode*>& res){
        if(l>r){
            return NULL;
        }
        
        int mid = l +(r-l)/2;
        
        TreeNode* root = new TreeNode(res[mid]->val);
        root->left = dfs(l, mid-1, res);
        root->right = dfs(mid+1, r, res);
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> res;
        inorder(root, res);
        return dfs(0, res.size()-1, res);
        
    }
};