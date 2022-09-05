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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // col -> <row-> pq<>>;
        typedef priority_queue<int, vector<int>, greater<int>> pq;
        map<int, vector<pq>> m;
        
        queue< pair<TreeNode*, pair<int, int>> > q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto f= q.front();
                q.pop();
                
                TreeNode* node = f.first;
                int r = f.second.first, c = f.second.second;
                int sz = m[c].size();
                int max_ = max(r+1, sz);
                m[c].resize(max_);
                m[c][r].push(node->val);
                
                if(node->left) q.push({node->left, {r+1, c-1}});
                if(node->right) q.push({node->right, {r+1, c+1}});
                
            }
        }
        
        vector<vector<int>> res;
        
        for(auto it=m.begin();it!=m.end();it++){
            auto info = it->second;
            
            vector<int> temp;
            
            for(int i=0;i<info.size();i++){
                auto pq = info[i];
                if(pq.size()!=0){
                    while(!pq.empty()){
                        temp.push_back(pq.top());
                        pq.pop();
                    }
                    
                }
            }
            
            res.push_back(temp);
            
        }
        
        return res;
    }
};