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
private:
    unordered_map<TreeNode*, int> robbed;
    unordered_map<TreeNode*, int> notRobbed;
   
    int dfs(TreeNode* root, int parentRobbed){
        if(!root) return 0;
        
        
        int rob=-1, notRob=-1;
        
        if(parentRobbed){
            if(robbed.find(root)!=robbed.end()) return robbed[root];
            
            notRob = dfs(root->left, 0) + dfs(root->right, 0);
            robbed[root]=notRob;
            return notRob;
        } else{
            if(notRobbed.find(root)!=notRobbed.end()) return notRobbed[root];
            
            rob = root->val + dfs(root->left, 1) + dfs(root->right, 1);
            notRob = dfs(root->left, 0) + dfs(root->right, 0);
            int res = max(rob, notRob);
            notRobbed[root]=res;
            return res;    
        }
        
    }
public:
    int rob(TreeNode* root) {
        return dfs(root, 0);
        
    }
};