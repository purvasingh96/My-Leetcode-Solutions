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
    void dfs(TreeNode* root, unordered_map<long long, int> m, long long presum, int k, int& ans){
        if(!root) return;
        
        presum += root->val;
        
        if(presum == k) ans+=1;
        
        if(m.find(presum - k)!=m.end()) ans += m[presum - k];
        
        m[presum]+=1;
        
        dfs(root->left, m, presum, k, ans);
        dfs(root->right, m, presum, k, ans);
    }
public:
    
    int pathSum(TreeNode* root, int k) {
        int ans=0;
        long long presum=0L;
        unordered_map<long long, int> m;
        
        dfs(root, m, presum, k, ans);
        return ans;
    }
};