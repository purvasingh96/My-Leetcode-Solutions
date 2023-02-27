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
    int inorderIdx(vector<int>& inorder, int val, int start, int end){
        for(int i=start;i<=end;i++){
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode* build(int& idx, int left, int right, vector<int>& preorder, vector<int>& inorder){
        if(left > right) return NULL;
        
        TreeNode* node = new TreeNode(preorder[idx]);
        
        int mid = inorderIdx(inorder, preorder[idx], left, right);
        idx+=1;
        node->left = build(idx, left, mid-1, preorder, inorder);
        node->right = build(idx, mid+1, right, preorder, inorder);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return build(idx, 0, (int)preorder.size()-1, preorder, inorder);   
    }
};