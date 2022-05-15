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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        int levelsum=0;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()) {
            
            int n = q.size();
            levelsum = 0;
            
            for(int i=0;i<n;i++) {
                auto f = q.front();
                q.pop();
                
                levelsum += f->val;
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            
        }
        
        return levelsum;
    }
};