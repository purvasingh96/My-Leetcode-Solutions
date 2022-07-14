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
    int findInorderIdx(int val, int start, int end, vector<int>& inorder){
        int ans=-1;
        
        for(int i=start;i<=end;i++){
            if(inorder[i] == val) {
                ans=i;
                break;
            }    
        }
        
        return ans;
    }
    
    TreeNode* dfs(int& idx, int start, int end, vector<int>& preorder, vector<int>& inorder){
        if(idx>=preorder.size()) return NULL;
        if(start>end) return NULL;
        
        int inorderIdx = findInorderIdx(preorder[idx++], start, end, inorder);
        TreeNode* root = new TreeNode(inorder[inorderIdx]);
        
        if(start==end) return root;
        
        
        
        root->left = dfs(idx, start, inorderIdx-1, preorder, inorder);
        root->right = dfs(idx, inorderIdx+1, end, preorder, inorder);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int idx=0;
        return dfs(idx, 0, preorder.size()-1, preorder, inorder);
    }
};