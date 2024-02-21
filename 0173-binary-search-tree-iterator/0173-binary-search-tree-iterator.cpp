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
    TreeNode* head;
    TreeNode* rootCopy;
    BSTIterator(TreeNode* root) {
        head =  root;
        rootCopy = root;
    }
    // Morris?
    int next() {
        while(head){
            if(head->left==NULL){
                int ans = head->val;
                head = head->right;
                return ans;
            } else {
                TreeNode* pred = head->left;
                while(pred->right!=NULL && pred->right!=head){
                    pred = pred->right;
                }
                if(pred->right==NULL){
                    pred->right=head;
                    head = head->left;
                } else {
                    pred->right=NULL;
                    int ans = head->val;
                    head = head->right;
                    return ans;
                }
            }
        }
        
        return head->val;
    }
    
    bool hasNext() {
        return head!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */