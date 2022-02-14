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
    
    int maxDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        vector<pair<TreeNode*, int>> my_stack;
        int max_depth=0;
        
        my_stack.push_back(make_pair(root, 1));
        
        while(!my_stack.empty()) {
            
            auto top = my_stack.back();
            my_stack.pop_back();
            
            TreeNode* next_node = top.first;
            int next_level = top.second;
            
            max_depth = max(max_depth, next_level);
            
            if(next_node->left) {
                my_stack.push_back(make_pair(next_node->left, next_level+1));
            }
            
            if(next_node->right) {
                my_stack.push_back(make_pair(next_node->right, next_level+1));
            }
            
        }
        
        return max_depth;
        
    }
};