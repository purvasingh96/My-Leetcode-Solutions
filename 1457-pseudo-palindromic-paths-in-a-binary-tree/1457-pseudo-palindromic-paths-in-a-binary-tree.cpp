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

    void dfs(TreeNode* root, vector<int> m, int odds, int& count) {
        if(!root) return;
        
        m[root->val] +=1;
        
        if(m[root->val]%2==0){
            odds-=1;
        } else {
            odds+=1;
        }
        
        if(!root->left && !root->right) {
            
            if(odds<=1) count+=1;
            
        }
        
        dfs(root->left, m, odds, count);
        dfs(root->right, m, odds, count);
        
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0, odds=0;
        vector<int> m(10, 0);
        dfs(root, m, odds, count);
        return count;
    }
};