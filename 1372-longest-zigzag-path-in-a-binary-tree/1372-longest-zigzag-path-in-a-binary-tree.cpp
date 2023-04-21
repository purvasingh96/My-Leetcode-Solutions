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
    int longestZigZag(TreeNode* root) {
        // direction, length, node
        queue<pair<pair<char, int>, TreeNode*>> q;
        q.push({{'L', 0}, root});
        int ans=0;
        
        while(!q.empty()){
            auto f = q.front();q.pop();
            char dir = f.first.first;
            int len = f.first.second;
            TreeNode* node = f.second;
            //cout<<node->val<<"\n";
            ans = max(ans, len);
            
            if(dir == 'L'){
               // cout<<"dir is l\n";
                if(node->right) q.push({{'R', len+1}, node->right});
                if(node->left) q.push({{'L', 1}, node->left});
                
            } else if(dir == 'R'){
                //cout<<"dir is R\n";
                if(node->left) q.push({{'L', len+1}, node->left});
                if(node->right) q.push({{'R', 1}, node->right});
            }
            
//             if(node->left) {
//                 //cout<<"q.push({{'R', 1}, node->right});\n";
//                 q.push({{'L', 1}, node->left});
//             }
//             if(node->right) {
                
//                 //cout<<"q.push({{'L', 1}, node->left});\n";
//                 q.push({{'R', 1}, node->right});
//             }
            
        }
        return ans;
    }
};