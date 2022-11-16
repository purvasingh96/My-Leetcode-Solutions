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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
       queue<TreeNode*> q;
        int count=0, level=0;
        
        q.push(root);
        
        bool isLastLevel=false;
        
        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--){
                auto f = q.front();
                q.pop();
                
                auto left = f->left, right = f->right;
                
                if(!right || (!left && !right)) isLastLevel = true; 
                
                if(left) q.push(left);
                if(right) q.push(right);
                
                
            }
            
            count+= pow(2, level);
            
             if(isLastLevel) {
                count+=q.size();
                break;
            } 
             
            level+=1;
        }
        
       return count;
        
    }
};