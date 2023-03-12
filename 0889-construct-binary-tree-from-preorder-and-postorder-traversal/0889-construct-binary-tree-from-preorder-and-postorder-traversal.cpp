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
    TreeNode* dfs(int& idx, int left, int right, vector<int>& preorder, vector<int>& postorder){
        if(left > right) return NULL;
        TreeNode* root = new TreeNode(preorder[idx++]);
        if(left == right) return root;
        int mid = find(postorder.begin(), postorder.end(), preorder[idx]) - postorder.begin();
        root->left = dfs(idx, left, mid, preorder, postorder);
        root->right = dfs(idx, mid+1, right-1, preorder, postorder);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int idx=0, n = preorder.size();
        return dfs(idx, 0, n-1, preorder, postorder);
    }
};