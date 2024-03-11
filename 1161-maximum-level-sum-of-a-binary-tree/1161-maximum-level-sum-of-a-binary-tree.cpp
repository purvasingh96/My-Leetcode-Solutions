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
        int maxSum = root->val;
        int level=1;
        int minLevel = level;
        
        while(!q.empty()){
            int sz = q.size();
            int sum=0;
            
            while(sz--){
                auto f = q.front();
                q.pop();
                sum += f->val;
                if(f->left){
                    q.push(f->left);
                }
                
                if(f->right){
                    q.push(f->right);
                }
            }
            if(sum > maxSum){
                maxSum = sum;
                minLevel = level;
            }
            level+=1;
        }
        
        return minLevel;
        
    }
};