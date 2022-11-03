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
        q.push(root);
        vector<int> res;
        if(!root) return res;
        
        while(!q.empty()){
            
            int sz = q.size();
            res.push_back(q.front()->val);
            
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
                
            }
        }
        
        return res;
    }
};