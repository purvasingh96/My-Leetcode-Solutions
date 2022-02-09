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
    void inorder(TreeNode* root, vector<int>& res) {
        if(!root) return;
        else{
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    
    
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> inord;
        inorder(root, inord);
        int mindiff = INT_MAX;
        
        for(int i=0;i<inord.size()-1;i++) {
            int x=inord[i];
            int y=inord[i+1];
            
            int diff = abs(x-y);
            
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }
};