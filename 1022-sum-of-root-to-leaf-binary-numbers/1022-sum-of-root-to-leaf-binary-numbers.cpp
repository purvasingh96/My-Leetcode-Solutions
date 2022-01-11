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
public:
    int binaryToDecimal(string binary) {
        
        int decimal = stoi(binary, 0, 2);
        return decimal;
        
    }
    
    void dfs(TreeNode* root, string res, int& ans) {
        
        if(!root) return;
        
        if(!root->left && !root->right) {
            res += to_string(root->val);
            ans += binaryToDecimal(res);
            return;
        }
        
        res += to_string(root->val);
        
        dfs(root->left, res, ans);
        dfs(root->right, res, ans);
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string res = "";
        
        dfs(root, res, ans);
        
        return ans;
        
    }
};