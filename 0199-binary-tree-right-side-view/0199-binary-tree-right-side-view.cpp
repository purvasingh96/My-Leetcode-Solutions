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
        res.push_back(root->val);
        
        while(!q.empty()){
            int sz = q.size();
            int rightmost=true;
            
            while(sz--){
                auto f = q.front(); 
                q.pop();
                if(f->right){
                    q.push(f->right);
                    if(rightmost){
                        res.push_back(f->right->val);
                        rightmost = false;
                    } 
                }
                if(f->left){
                    q.push(f->left);
                    if(rightmost){
                        res.push_back(f->left->val);
                        rightmost = false;
                    }
                }
            }
            
        }
        
        return res;
    }
};