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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        
        while(!q.empty()){
            int n =q.size();
            double avg=0.0;
            
            for(int i=0;i<n;i++){
                
                auto f = q.front();
                q.pop();
                avg += (f->val);
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            
            avg = (avg/n);
            res.push_back(avg);
        }
        
        return res;
    }
};