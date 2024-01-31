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
    vector<int> sortNodes(vector<pair<int, int>>& nodes){
        vector<int> res;
        sort(nodes.begin(), nodes.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        for(auto node:nodes){
            res.push_back(node.first);
        }
        return res;
    }
    
    void inorder(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>& res){
        if(!root) return;
        inorder(root->left, row+1, col-1, res);
        res[col].push_back({root->val, row});
        inorder(root->right, row+1, col+1, res);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int, int>>> res;
        inorder(root, 0, 0, res);
        vector<vector<int>> ans;
        for(auto val:res){
           ans.push_back(sortNodes(val.second));
        }
        return ans;
    }
};