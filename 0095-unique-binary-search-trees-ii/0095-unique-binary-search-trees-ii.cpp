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
    vector<TreeNode*> backtrack(int start, int end, map<pair<int, int>, vector<TreeNode*>>& dp){
        vector<TreeNode*> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        
        if(dp.find({start, end})!=dp.end()) return dp[{start, end}];
        
        
        for(int i=start;i<=end;i++){
            auto left = backtrack(start, i-1, dp);
            auto right = backtrack(i+1, end,  dp);
            
            for(auto l:left){
                for(auto r:right) {
                    TreeNode* root = new TreeNode(i, l, r);
                    res.push_back(root);
                }
            }
        
        }
        
        return dp[{start, end}] = res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;
        
        return backtrack(1, n, dp);
        
    }
};