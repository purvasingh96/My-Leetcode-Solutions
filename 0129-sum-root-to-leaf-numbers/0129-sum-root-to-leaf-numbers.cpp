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
    void dfs(TreeNode* root, int& num, int& sum){
        if(!root) return;
        
        num = num*10 + root->val;
        if(!root->left && !root->right){
            sum += num;
        }
        
        dfs(root->left, num, sum);
        dfs(root->right, num, sum);
        num-= root->val;
        num=num/10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int num=0;
        int sum=0;
        dfs(root, num, sum);
        return sum;
    }
};