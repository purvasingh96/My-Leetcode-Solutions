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
        unordered_map<int, vector<int>> m;
        vector<vector<int>> res;
        // node, {row, col}
        queue<pair<TreeNode*, pair<int, int>>> q;
        int minCol=INT_MAX, maxCol = INT_MIN;
        if(!root) return res;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            auto node = x.first;
            int row = x.second.first, col = x.second.second;
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
            m[col].push_back(node->val);
            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right, {row+1, col+1}});
            }
        }
        
        
        for(int i=minCol;i<=maxCol;i++){
            res.push_back(m[i]);
        }
        
        return res;
        
    }
};