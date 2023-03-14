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
    int postOrderIdx;
    int inorderIdx(vector<int>& inorder, int val, int start, int end){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode* build(int left, int right, vector<int>& inorder, vector<int>& postorder){
        //cout<<"left: "<<left<<" right: "<<right<<"\n";
        if(left > right) return NULL;
        
        
        int val = postorder[postOrderIdx];
        TreeNode* root = new TreeNode(val);
        int mid = inorderIdx(inorder, val, left, right);
        postOrderIdx--;
        if(left == right) return root;
        root->right = build(mid+1, right, inorder, postorder);
        root->left = build(left, mid-1, inorder, postorder);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size()-1;
        postOrderIdx = n;
        return build(0, n, inorder, postorder);
    }
};