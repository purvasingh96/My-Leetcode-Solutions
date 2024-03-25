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
    int sumEvenGrandparent(TreeNode* root) {
        // root, 
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f->val%2==0){
                    // look for grandchildren
                    if(f->left){
                        TreeNode* leftNode = f->left;
                        sum += leftNode->left!= NULL ? leftNode->left->val : 0;
                        sum += leftNode->right!= NULL ? leftNode->right->val : 0;
                    }
                    
                    if(f->right){
                        TreeNode* rightNode = f->right;
                        sum += rightNode->left != NULL ? rightNode->left->val : 0;
                        sum += rightNode->right != NULL ? rightNode->right->val : 0;
                    }
                    
                    
                }
                
                if(f->left){
                    q.push(f->left);
                }
                
                if(f->right){
                    q.push(f->right);
                }
                
            }
        }
        
        return sum;
        
    }
};