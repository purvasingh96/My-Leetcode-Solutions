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
    int dfs(TreeNode* root, int p, int q, int& pdist, int& qdist, int dist){
        if(!root){
            return 0;
        }
        auto l = dfs(root->left, p, q, pdist, qdist, dist+1);
        auto r = dfs(root->right, p, q, pdist, qdist, dist+1);
        
        if(root->val == p){
            pdist = dist;
            return pdist;
        }
        
        if(root->val == q){
            qdist = dist;
            return qdist;
        }
        
        if(l && r){
            return dist;
        }
        
        return l ? l : r;
        
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        if(p==q){
            return 0;
        }
        int pdist=0, qdist=0, dist=0;
        int d = dfs(root, p, q, pdist, qdist, dist);
        return pdist+qdist - 2*d;
    }
};