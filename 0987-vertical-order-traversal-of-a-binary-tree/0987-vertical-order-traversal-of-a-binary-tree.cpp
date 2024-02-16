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
        if(!root){
            return;
        }
        
        m[col].push_back({root->val, row});
        dfs(root->left, row+1, col-1, m);
        dfs(root->right, row+1, col+1, m);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        dfs(root, 0, 0, m);
        vector<vector<int>> res;
        
        for(auto x:m){
            vector<pair<int, int>> temp = x.second;
            sort(temp.begin(), temp.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                if(a.second == b.second){
                    return a.first < b.first;
                }
                return a.second < b.second;
            });
            vector<int> ans;
            for(auto y:temp){
                ans.push_back(y.first);
            }
            res.push_back(ans);
        }
        
        return res;
    }
};