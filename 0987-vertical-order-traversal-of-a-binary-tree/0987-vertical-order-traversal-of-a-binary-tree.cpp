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
class Info{
public:
    TreeNode* node;
    int row;
    int col;
    Info(TreeNode* node, int row, int col){
        this->node = node;
        this->row=row;
        this->col=col;
    }
};

class Solution {
private:
    int height(TreeNode* root){
        if(!root) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    void dfs(TreeNode* root, int idx, vector<vector<int>>& res){
        queue<Info*> q;
        Info* i = new Info(root, idx, idx);
        q.push(i);
        while(!q.empty()){
            int sz = q.size();
            vector<Info*> temp;
            
            while(sz--){
                auto f = q.front();q.pop();
                
                temp.push_back(f);
                
                if(f->node->left) {
                    Info* left = new Info(f->node->left, f->row+1, f->col-1);
                    q.push(left);
                }
                if(f->node->right) {
                    Info* right = new Info(f->node->right, f->row+1, f->col+1);
                    q.push(right);
                }
            }
            
            sort(temp.begin(), temp.end(), [](const Info* a, const Info* b){
               return a->node->val < b->node->val; 
            });
            
            //cout<<temp.size()<<"\n";
            
            for(auto x:temp){
                res[x->col].push_back(x->node->val);
            }
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int idx = height(root);
        vector<vector<int>> res(2*idx);
        dfs(root, idx, res);
        vector<vector<int>> ans;
        for(auto x:res){
            if(x.size()==0) continue;
            ans.push_back(x);
        }
        return ans;
    }
};