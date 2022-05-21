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
    int findPosInInorder(vector<int> inorder, int start, int end, int target) {
        for(int i=start;i<=end;i++) {
            if(inorder[i] == target) return i;
        }
        
        return 0;
    }
    
public:
    TreeNode* dfs(vector<int> in, vector<int> post, int start, int end, int& idx){
        
        if(start>end || idx<0) return NULL;
        
        if(start == end) {
            TreeNode* new_root = new TreeNode(in[start]);
            idx-=1;
            return new_root;
        }
        
        TreeNode* root = new TreeNode(post[idx]);
        int pos = findPosInInorder(in, start, end, post[idx]);
        idx-=1;
        root->right = dfs(in, post, pos+1, end, idx);
        root->left = dfs(in, post, start, pos-1, idx);
        
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return dfs(inorder, postorder, 0, inorder.size()-1, idx);
    }
};