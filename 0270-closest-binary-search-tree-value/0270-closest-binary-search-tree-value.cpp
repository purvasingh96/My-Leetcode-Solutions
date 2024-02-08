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
    void dfs(TreeNode* root, vector<int>& res){
        if(!root) return;
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
public:
    int closestValue(TreeNode* root, double target) {
        vector<int> res;
        dfs(root, res);
        
        sort(res.begin(), res.end(), [&](const int& a, const int& b){
            if(abs(target - a) != abs(target -b)){
                return abs(target - a) < abs(target-b);
            }
            return a<b;
        });
        
        return res[0];
    }
};