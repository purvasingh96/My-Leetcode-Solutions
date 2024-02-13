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
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->val);
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            int rightmost=INT_MIN;
            while(sz--){
                auto f = q.front();
                q.pop();
                if(f->right) {
                    q.push(f->right);
                    if(rightmost == INT_MIN){
                        rightmost = f->right->val;    
                    }
                }
                if(f->left){
                    q.push(f->left);
                    if(rightmost==INT_MIN){
                        rightmost = f->left->val;
                    }
                }
            }
            if(rightmost != INT_MIN){
                ans.push_back(rightmost);    
            }
        }
        
        return ans;
    }
};