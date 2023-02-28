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
    string serialize(TreeNode* root, unordered_map<string, int>& cnt, vector<TreeNode*>& res){
        if(!root) return "";
        
        string rep = "(" + serialize(root->left, cnt, res) + ")" + to_string(root->val) + "(" +serialize(root->right, cnt, res) + ")";
        cnt[rep] += 1;
        if(cnt[rep]==2) {
            res.push_back(root);
        }
        return rep;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> cnt;
        serialize(root, cnt, res);
        return res;
    }
};