/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, int depth, unordered_map<TreeNode*, bool>& visited, unordered_map<TreeNode*, TreeNode*>& parent, int k, vector<int>& res){
        
        if(depth == k){
            res.push_back(root->val);
            return;
        }
        
        if(parent[root]!=NULL && visited[parent[root]] == false){
            visited[parent[root]]=true;
            dfs(parent[root], depth+1, visited, parent, k, res);
        }
        
        if(root->left && visited[root->left]==false){
            visited[root->left]=true;
            dfs(root->left, depth+1, visited, parent, k, res);
        }
        
        if(root->right && visited[root->right]==false){
            visited[root->right]=true;
            dfs(root->right, depth+1, visited, parent, k, res);
        }
        
    
        
    }
    
    void fillParents(TreeNode* root, TreeNode* p, unordered_map<TreeNode*, TreeNode*>& parent, unordered_map<TreeNode*, bool>& visited){
        if(!root) return;
        parent[root] = p;
        visited[root] = false;
        fillParents(root->left, root, parent, visited);
        fillParents(root->right, root, parent, visited);
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, bool> visited;
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> res;
        fillParents(root, NULL, parent, visited);
        visited[target] = true;
        dfs(target, 0, visited, parent, k, res);
        return res;
    }
};