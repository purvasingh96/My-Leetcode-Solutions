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
    void dfs(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>& m){
        if(!root) return;
        dfs(root->left, row+1, col-1, m);
        m[col].push_back({row, root->val});
        dfs(root->right, row+1, col+1, m);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> m;
        
        dfs(root, 0, 0, m);
        
        for(auto x:m){
            vector<pair<int, int>> temp = x.second;
            
            sort(temp.begin(), temp.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                return a.first < b.first;
            });
            vector<int> temp2;
            for(auto x:temp){
                temp2.push_back(x.second);
            }
            res.push_back(temp2);
        }
        
        return res;
    }
};