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
    void customSwap(int i, int j, vector<int>& level){
        int t = level[i];
        level[i] = level[j];
        level[j]=t;
    }
    
    int cycleSort(vector<int>& level){
        vector<int> x = level;
        sort(x.begin(), x.end());
        unordered_map<int, int> m;
        
        // sorted array
        for(int i=0;i<x.size();i++) {
            m[level[i]] = i;
        }
        
        int count=0;
        
        for(int i=0;i<x.size();i++){
            if(level[i]!=x[i]){
                
                int og_level_idx = m[level[i]], og_x_idx = m[x[i]];
                int level_val = level[i], x_val = x[i];
                
                customSwap(i, m[x[i]], level);
                m[level_val] = og_x_idx;
                m[x_val] = og_level_idx;
                
                count+=1;
                
            }
            
        }
        
        return count;
    }
    
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        vector<int> level;
        int l=0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                if(f->left){
                    q.push(f->left);
                    level.push_back(f->left->val);
                }
                
                
                if(f->right){
                    q.push(f->right);
                    level.push_back(f->right->val);
                }
                
            }
            
            l+=1;
            
            if(level.size() > 0){
                int s = cycleSort(level);
                
                ans += s;
                level.clear();
            }
            
        }
        
        return ans;
        
        
        
        
        
    }
    
    
    
};