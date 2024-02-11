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
    void dfs(TreeNode* root, double target, double& minSoFar, int& node){
        if(!root) return;
        double diff = abs(root->val - target);
        if(diff<minSoFar){
            minSoFar = diff;
            node = root->val;
        } else if(diff == minSoFar){
            if(root->val < node){
                node = root->val;
            }
        }
        
        if(target > root->val){
            dfs(root->right, target, minSoFar, node);
        } else if(target <= root->val) {
            dfs(root->left, target, minSoFar, node);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        double minSoFar=INT_MAX;
        int node = root->val;
        dfs(root, target, minSoFar, node);
        return node;
    }
};