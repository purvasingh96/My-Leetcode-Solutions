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
class BSTIterator {
public:
    TreeNode* root;
    BSTIterator(TreeNode* head) {
        root = head;
    }
    
    int next() {
        
        while(root){
        if(!root->left){
            int ans = root->val;
            root=root->right;
            return ans;
        } else {
            TreeNode* pred = root->left;
            while(pred->right!=NULL && pred->right!=root){
                pred = pred->right;
            }
            if(pred->right==NULL){
                pred->right=root;
                root=root->left;
            } else if(pred->right==root){
                pred->right=NULL;
                int ans = root->val;
                root = root->right;
                return ans;
            }
        }
        }
        return root->val;
    }
    
    bool hasNext() {
        return root!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */