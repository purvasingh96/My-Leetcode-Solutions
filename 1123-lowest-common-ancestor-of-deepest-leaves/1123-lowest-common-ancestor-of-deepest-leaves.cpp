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
    TreeNode* ans;
    int leafDepth(TreeNode* root, int d, int& maxD){
        if(!root) return d - 1;
        int l = leafDepth(root -> left, d + 1, maxD);
        int r = leafDepth(root -> right, d + 1, maxD);
        int leafD = max(l, r);
        maxD = max(maxD, leafD);
        if(maxD == l && l == r) ans = root;
        return leafD;
        
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxD = 0;
        leafDepth(root, 0, maxD);
        return ans;
    }
};