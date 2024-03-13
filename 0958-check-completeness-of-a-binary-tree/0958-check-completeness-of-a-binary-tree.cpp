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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullNodeFound=false;
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            if(!f){
                nullNodeFound=true;
            } else {
                if(nullNodeFound){
                    return false;
                }
                q.push(f->left);
                q.push(f->right);
                    
            }
        }
        
        return true;
    }
};