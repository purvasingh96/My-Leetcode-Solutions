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
    #define NOT_COVERED 0
    #define COVERED 1
    #define HAS_CAMERA 2
    
    int ans=0;
    
    int dfs(TreeNode* root){
        
        if(!root){
            return COVERED;
        }
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l==NOT_COVERED || r==NOT_COVERED){
            ans+=1;
            return HAS_CAMERA;
        }
        
        else if(l == HAS_CAMERA || r==HAS_CAMERA){
            return COVERED;
        }
        
        return NOT_COVERED;
        
        
    }
    
    int minCameraCover(TreeNode* root) {
        return dfs(root) == NOT_COVERED ? ++ans:ans;
    }
};