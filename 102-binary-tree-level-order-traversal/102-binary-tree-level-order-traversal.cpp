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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        
        while(!q.empty()){
            
            int s= q.size();
            vector<int> temp;
            
            for(int i=0;i<s;i++){
                
                auto f = q.front();
                q.pop();
                temp.push_back(f->val);
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
            }
            
            res.push_back(temp);
            
        }
        
        return res;
    }
};