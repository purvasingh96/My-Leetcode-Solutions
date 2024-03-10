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
    TreeNode* res;
    int lca(TreeNode* root, vector<int> leaves){
        if(!root){
            return 0;
        }
        
        // leaf nodes
        if(find(leaves.begin(), leaves.end(), root->val)!=leaves.end()){
            if(leaves.size() == 1 && !res){
                res=root;
            }
            return 1;
        }
        
        int l = lca(root->left, leaves);
        int r = lca(root->right,leaves);
        //cout<<"root->val:: "<<root->val<<" l: "<<l<<" r: "<<r<<"\n";
        
        if(l+r == leaves.size() && !res){
            res = root;
        }
        
        return l+r;
       
    }
    
    void collectDeepestLeaves(TreeNode* root, int d, map<int, vector<int>>& leaves){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            leaves[d].push_back(root->val);
        }
        
        collectDeepestLeaves(root->left, d+1, leaves);
        collectDeepestLeaves(root->right, d+1, leaves);
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        res = NULL;
        if(!root){
            return res;
        }
        
        map<int, vector<int>> leaves;
        collectDeepestLeaves(root, 0, leaves);
        
        lca(root, leaves.rbegin()->second);
        return res;
    }
};