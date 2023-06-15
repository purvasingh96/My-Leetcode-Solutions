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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=1, ans=0, maxSum=INT_MIN;
        
        while(!q.empty()){
            int sum=0;
            int sz=q.size();
            while(sz--){
                auto f = q.front();q.pop();
                sum += f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                ans = level;
            }
            level+=1;
        }
        
        return ans;
        
    }
};