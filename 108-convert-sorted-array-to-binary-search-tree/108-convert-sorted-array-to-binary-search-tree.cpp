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
    TreeNode* dfs(int start, int end, vector<int>& nums){
        if(start>end) return NULL;
        int mid = start + (end-start+1)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = dfs(start, mid-1, nums);
        root->right = dfs(mid+1, end, nums);
        
        return root;
        
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size()-1, nums);
    }
};