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
    void dfs(TreeNode* root, priority_queue<int> pq, int& good){
        if(!root) return;
        
        if(pq.empty() || pq.top()<=root->val) good+=1;
        
        pq.push(root->val);
        
        dfs(root->left, pq, good);
        dfs(root->right, pq, good);
        
        
    }
public:
    int goodNodes(TreeNode* root) {
        int good=0;
        priority_queue<int> pq;
        dfs(root, pq, good);
        return good;
    }
};