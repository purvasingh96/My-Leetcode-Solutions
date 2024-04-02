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
    TreeNode* str2tree(string s) {
        if(s.length()==0){
            return NULL;
        }
        
        TreeNode* ans=NULL;
        stack<TreeNode*> st;
        int d=0;
        char op = '(';
        
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int j=i;
                while(j<s.length() && isdigit(s[j])){
                    d=d*10 + (s[j]-'0');
                    j+=1;
                }
                i=j-1;
                if(op == '-'){
                    d = d*-1;
                }
                TreeNode* node = new TreeNode(d);
                if(st.empty()){
                    st.push(node);
                } else {
                    if(st.top()->left==NULL){
                        st.top()->left = node;
                    } else {
                        st.top()->right = node;
                    }
                    st.push(node);
                }
                d=0;
            } else {
                op = s[i];
                if(op == ')'){
                    if(!st.empty()){
                        st.pop();
                    }
                }
            }
        }
        
        return st.size()>0 ? st.top():NULL;
    }
};