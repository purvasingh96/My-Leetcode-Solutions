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
    void dfs(TreeNode* root, double target, double& minVal, int& node){
        if(!root) return;
        double dist = abs(root->val - target);
            if(dist<minVal){
                minVal = dist;
                node = root->val;
            } else if(dist == minVal){
                if(root->val < node){
                    node = root->val;
                }
            }
        
        if(root->val >= target){
            dfs(root->left, target, minVal, node);
        } else if(target > root->val) {
            dfs(root->right, target, minVal, node);    
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        int node = root->val;
        double minVal=INT_MAX;
        dfs(root, target, minVal, node);
        return node;
    }
};