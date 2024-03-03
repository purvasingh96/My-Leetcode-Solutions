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
        if(!root){
         return {};   
        }
        queue<TreeNode*> q;
       vector<int> ans;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            bool foundRight=false;
            
            while(sz--){
                auto f = q.front();
                q.pop();
                if(!foundRight){
                    ans.push_back(f->val);
                    foundRight = true;
                }
                
                
                if(f->right){
                    q.push(f->right);
                } 
                if(f->left){
                    q.push(f->left);
                }
                
            }
        }
        return ans;
    }
};