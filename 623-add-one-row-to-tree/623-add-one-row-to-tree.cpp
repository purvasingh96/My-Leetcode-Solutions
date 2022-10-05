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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* x = new TreeNode(val);
            x->left = root;
            return x;
        } 
        
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        
        while(!q.empty()){
            
            int sz=q.size();
            bool found =false;
            
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                if(level==depth-1){
                    found=true;
                    TreeNode* l = f->left;
                    TreeNode* r = f->right;
                    
                    TreeNode* vl = new TreeNode(val);
                    TreeNode* vr = new TreeNode(val);
                    
                    f->left = vl;
                    f->right=vr;
                    vl->left = l;
                    vr->right=r;
                    
                } else {
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
                
                
            }
            if(found) break;
            level += 1;
            
        }
        
        return root;
    }
};