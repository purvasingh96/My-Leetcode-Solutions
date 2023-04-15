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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, int> sum;
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        
        while(!q.empty()){
            int sz = q.size();
            int total=0;
            
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f->left) {
                    sum[f] += f->left->val;
                    q.push(f->left);
                    adj[f].push_back(f->left);
                    total+=f->left->val;
                }
                if(f->right) {
                    sum[f] += f->right->val;
                    q.push(f->right);
                    adj[f].push_back(f->right);
                    total+=f->right->val;
                }
                
            }
            //cout<<"total: "<<total<<"\n";
            for(auto x:adj){
                int newVal = total - sum[x.first];
                for(auto y:x.second){
                    y->val = newVal;
                }
            }
            adj.clear();
            sum.clear();
            
        }
        
        root->val = 0;
        return root;
        
    }
};