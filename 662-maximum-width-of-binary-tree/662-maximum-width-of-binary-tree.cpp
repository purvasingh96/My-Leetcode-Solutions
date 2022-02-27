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
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int max_width=0;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            
            int start = q.front().second;
            int end = q.back().second;
            
            max_width = max(max_width, (end-start+1));
            
            int s = q.size();
            
            for(int i=0;i<s;i++) {
                
                auto f = q.front();
                q.pop();
                
                int idx = f.second - start;
                
                if(f.first->left) {
                    
                    q.push({f.first->left, (long long)2*idx});
                }
                
                if(f.first->right) {
                    
                    q.push({f.first->right, (long long)2*idx+1});
                    
                }
                
                
            }
            
        }
        
        return max_width;
        
    }
};