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
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root, res);
        int n = res.size();
        
        int left = 0, right=n-1;
        
        while(left<right){
            int sum = res[left] + res[right];
            if(sum==k) return true;
            else if(sum < k) left+=1;
            else right-=1;
        }
        
        return false;
        
    }
};