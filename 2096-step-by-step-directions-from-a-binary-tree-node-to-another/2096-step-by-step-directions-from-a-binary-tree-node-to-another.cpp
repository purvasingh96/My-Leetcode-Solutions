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
    
    
    void dfs(TreeNode* root, string& s, string& start, string& dest, int startVal, int destVal) {
        if(!root) return;
        if(root->val == startVal) start = s;
        else if(root->val == destVal) dest = s;
        
        if(root->left!=NULL){
            s += "L";
            dfs(root->left, s, start, dest, startVal, destVal);
            s.pop_back();
        } 
        
        if(root->right!=NULL){
            s+="R";
            dfs(root->right, s, start, dest, startVal, destVal);
            s.pop_back();
        }
    }
    
public:
    string getDirections(TreeNode* root, int startVal, int destVal) {
        
        string start="", dest="", s="";
        
        dfs(root, s, start, dest, startVal, destVal);
        
        int ln = start.length(), rn=dest.length();
        
        if(ln==0) return dest;
        
        int idx = lcp(start, dest);
        string st(ln-idx, 'U');
        
        return st+dest.substr(idx);
    }
};