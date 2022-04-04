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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return res;
        
        q.push(root);
        
        while(!q.empty()) {
            
            int s = q.size();
            auto top = q.front();
            res.push_back(top->val);
            
            for(int i=0;i<s;i++) {
                
                auto top = q.front();
                q.pop();
                
                if(top->right) {
                    q.push(top->right);
                }
                if(top->left) {
                    q.push(top->left);
                }
                
            }
            
            
            
        }
        
        return res;
    }
};