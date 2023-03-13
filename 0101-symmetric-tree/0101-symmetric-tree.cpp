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
    bool isMirror(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        return (a->val == b->val && isMirror(a->left, b->right) && isMirror(a->right, b->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};