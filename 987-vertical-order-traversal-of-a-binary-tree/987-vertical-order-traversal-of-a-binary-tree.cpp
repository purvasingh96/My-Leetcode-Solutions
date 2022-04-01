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
    void dfs(TreeNode* root, map<int, vector<priority_queue<int, vector<int>, greater<int>>>>& m, int row, int col) {
        
        if(!root) return;
        m[col].resize(20);
        
        //cout<<(m[col][row].size())<<"\n";
        m[col][row].push(root->val);
        
        
        if(root->left) {
            dfs(root->left, m, row+1, col-1);
        }
        
        if(root->right) {
            dfs(root->right, m, row+1, col+1);
        }
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<priority_queue<int, vector<int>, greater<int>>>> m;
        vector<vector<int>> res;
        
        dfs(root, m, 0, 0);
        
        for(auto x:m) {
            vector<int> temp;
            for(auto y:x.second) {
                
                if(!y.empty()) {
                    while(!y.empty()) {
                        int top = y.top();
                        temp.push_back(top);
                        y.pop();
                    }
                    
                }
            }
            res.push_back(temp);
        }
        
        return res;
        
    }
};