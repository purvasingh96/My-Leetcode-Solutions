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
    vector<int> inorder(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* curr = root;
        
        while(!st.empty() || curr!=NULL){
           while(curr){
               st.push(curr);
               curr=curr->left;
           }
            
            curr = st.top();st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        
        return res;
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;        
        auto x = inorder(root);
        int n = x.size();
        if(n==1) return x[0];
        
        int minDiff=INT_MAX;
        for(int i=0;i<n-1;i++) {
            minDiff = min(minDiff, (x[i+1] - x[i]));
        }
        
        return minDiff;
    }
};