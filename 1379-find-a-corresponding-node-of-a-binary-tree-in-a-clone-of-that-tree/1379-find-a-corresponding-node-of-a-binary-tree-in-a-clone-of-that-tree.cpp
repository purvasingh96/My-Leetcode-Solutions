/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<TreeNode*> q;
        q.push(cloned);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i=0;i<n;i++) {
                
                    auto f = q.front();
                    q.pop();

                    if(f->val == target->val) return f;

                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                
            }
        }
        
        return NULL;
    }
};