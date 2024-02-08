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
    int closestValue(TreeNode* root, double target) {
        int closestNode=root->val;
        int val;
        while(root){
            val = root->val;
            if(abs(target - val) < abs(target - closestNode) || 
              (abs(target - val) == abs(target - closestNode) && val < closestNode)){
                closestNode = val;
            }
            
            root = target < val ? root->left : root->right;
        }
        
        return closestNode;
    }
};