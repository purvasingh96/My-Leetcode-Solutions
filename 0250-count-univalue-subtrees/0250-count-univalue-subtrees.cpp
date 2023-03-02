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
pair<TreeNode*, bool> dfs(TreeNode* root, int& count){
    if(!root) return {NULL, true};
    if(!root->left && !root->right) {
        count+=1;
        return {root, true};
    }
    
    auto left = dfs(root->left, count);
    auto right = dfs(root->right, count);
    
    if(left.second && right.second){
        if(left.first && right.first){
            if(root->val == left.first->val && root->val == right.first->val){
                count+=1;
                return {root, true};
            } 
        } else{
            if(left.first){
                if(root->val == left.first->val){
                    count+=1;
                    return {root, true};
                }
            } 
            if(right.first){
                if(root->val == right.first->val){
                    count+=1;
                    return {root, true};
                }
            }
            
        }
    }
    
    
        
     return {root, false};   
}
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count=0;
        dfs(root, count);
        return count;
    }
};