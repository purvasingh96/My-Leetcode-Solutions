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
        if(!root) {
            return;
        }
        m[col].push_back({row, root->val});
        
        if(root->left){
            dfs(root->left, row+1, col-1, m);    
        }
        if(root->right){
            dfs(root->right, row+1, col+1, m);
        }
        
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        dfs(root, 0, 0,m);
        vector<vector<int>> res;
        for(auto x:m){
            sort(x.second.begin(), x.second.end(), [](const pair<int, int>& a, const pair<int, int>& b){
               if(a.first!=b.first){
                   return a.first < b.first;
               }
                return false;
            });
            vector<int> temp;
            for(auto y:x.second){
                temp.push_back(y.second);
            }
            res.push_back(temp);
        }
        
       
        return res;
    }
};