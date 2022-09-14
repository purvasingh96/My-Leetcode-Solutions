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
    int getNodes(vector<int> m){
        int sz=0;
        for(int i=1;i<=9;i++){
            if(m[i]>0) sz+=1;
        }
        return sz;
    }
    
    void dfs(TreeNode* root, vector<int> m, int& count) {
        if(!root) return;
        
        m[root->val] +=1;
        
        if(!root->left && !root->right) {
            bool isPseudoPalindromic=true;
            int sz = accumulate(m.begin(), m.end(), 0);
            if(sz%2==0){
                for(int i=1;i<=9;i++){
                    if(m[i]!=0 && m[i]%2!=0){
                        // found odd
                        isPseudoPalindromic = false;
                        break;
                    }
                }
                
            } 
            
            else {
                
                int countOdd=0;
                for(int i=1;i<=9;i++){
                    if(m[i]!=0 && m[i]%2!=0){
                        countOdd+=1;
                        if(countOdd>1) {
                            isPseudoPalindromic = false;
                            break;
                        }
                    }
                }   
            }
            
            if(isPseudoPalindromic) count+=1;
            return;
        }
        
            dfs(root->left, m, count);
            dfs(root->right, m, count);
        
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int> m(10, 0);
        dfs(root, m, count);
        return count;
    }
};