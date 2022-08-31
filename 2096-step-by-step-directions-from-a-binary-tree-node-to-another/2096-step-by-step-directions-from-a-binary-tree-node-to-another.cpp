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
    int lcp(string& s1, string& s2){
        int i=0;
        while(i<s1.length() && i<s2.length()){
            if(s1[i]!=s2[i]) return i;
            i+=1;
        }
        return min(s1.length(), s2.length());
    }
    
    TreeNode* lcaHelper(TreeNode* root, int start, int dest) {
        if(!root) return NULL;
        
        if(root->val == start || root->val == dest) return root;
        
        TreeNode* left = lcaHelper(root->left, start, dest);
        TreeNode* right = lcaHelper(root->right, start, dest);
        
        if(left && right) return root;
        
        else if(left && !right) return left;
        
        else if(!left && right) return right;
        
        return NULL;
        
    }
    
    void dfs(TreeNode* root, int dest, string& res, string& s, bool& found){
        if(!root) return;
        
        if(root->val==dest) {
            s = res;
            found=true;
            return;
        }
        
        if(!found){
            if(root->left){
                res+="L";
                dfs(root->left, dest, res, s, found);
                res.pop_back();
            }
            
            if(root->right){
                res+="R";
                dfs(root->right, dest, res, s, found);
                res.pop_back();
            }
            
        }
        
        return;
    }
    
public:
    string getDirections(TreeNode* root, int startVal, int destVal) {
        
        TreeNode* lca = lcaHelper(root, startVal, destVal);
        string left="", right="", s="";
        bool found_start=false, found_dest=false;
        dfs(lca, startVal, s, left, found_start);
        s="";
        dfs(lca, destVal, s, right, found_dest);
        
        if(left.length()==0) return right;
        
        int idx = lcp(left,right);
        
        string st(left.length() - idx, 'U');
        
        return st+right.substr(idx);
    }
};