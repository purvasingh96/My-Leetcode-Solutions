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
    TreeNode* build(int& idx, int left, int right, vector<int>& preorder, vector<int>& postorder){
        if(left>right) return NULL;
        
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        if(left==right) return root;
       
        int i = find(postorder.begin(), postorder.end(), preorder[idx]) - postorder.begin();
        
        root->left = build(idx, left, i, preorder, postorder);
        root->right = build(idx, i+1, right-1, preorder, postorder);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int i=0;
        return build(i, 0, n-1, preorder, postorder);
    }
};