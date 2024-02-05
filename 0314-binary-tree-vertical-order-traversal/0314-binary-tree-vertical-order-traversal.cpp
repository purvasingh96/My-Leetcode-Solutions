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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        vector<vector<int>> res;
        // node, {row, col}
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if(!root) return res;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            auto node = x.first;
            int row = x.second.first, col = x.second.second;
            m[col].push_back(node->val);
            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right, {row+1, col+1}});
            }
        }
        
        
        for(auto x:m){
            res.push_back(x.second);
        }
        
        return res;
        
    }
};