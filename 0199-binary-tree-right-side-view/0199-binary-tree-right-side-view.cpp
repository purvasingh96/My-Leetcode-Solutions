class Solution {
public:
 
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode*> q;
        
        q.push(root);
        vector<int> res;
        if(!root) return res;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                if(sz==0) res.push_back(f->val);
            }
        }
        return res;
    }
};