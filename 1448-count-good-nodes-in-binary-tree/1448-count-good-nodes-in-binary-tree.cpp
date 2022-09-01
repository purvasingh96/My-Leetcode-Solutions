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
    void dfs(TreeNode* root, int maxval, int& good){
        if(!root) return;
        
        if(maxval==INT_MIN || maxval <= root->val) good+=1;
        
        maxval = max(maxval, root->val);
        
        dfs(root->left, maxval, good);
        dfs(root->right, maxval, good);
        
        
    }
public:
    int goodNodes(TreeNode* root) {
        int good=0;
        int maxval=INT_MIN;
        dfs(root, maxval, good);
        return good;
    }
};