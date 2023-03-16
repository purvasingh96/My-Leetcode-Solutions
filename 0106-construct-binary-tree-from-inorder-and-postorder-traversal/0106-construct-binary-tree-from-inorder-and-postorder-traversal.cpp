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
    TreeNode* dfs(int& idx, int left, int right, vector<int>& inorder, vector<int>& preorder){
        if(left>right) return NULL;
        if(idx<0) return NULL;
        
        int mid = find(inorder.begin(), inorder.end(), preorder[idx--]) - inorder.begin();
        TreeNode* root = new TreeNode(inorder[mid]);
        root->right = dfs(idx, mid+1, right, inorder, preorder);
        root->left = dfs(idx, left, mid-1, inorder, preorder);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return dfs(idx, 0, n-1, inorder, postorder);
    }
};