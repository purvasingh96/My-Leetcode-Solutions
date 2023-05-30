class MyHashSet {
    
public:
    TreeNode* root;
    MyHashSet() {
        root = NULL;
    }
    
    TreeNode* insert(TreeNode* root, int key){
        if(!root){
            return new TreeNode(key);
        } else {
            if(root->val > key){
                root->left = insert(root->left, key);
            } else if(root->val < key){
                root->right = insert(root->right, key);
            } else {
                root->val = key;
            }
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return NULL;
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else if(root->val < key){
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left && !root->right) return NULL;
            else if(!root->left || !root->right) {
                if(root->left) return root->left;
                return root->right;
            }
            else if(root->left && root->right){
                TreeNode* pred = root->left;
                while(pred->right){
                    pred = pred->right;
                }
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        return root;
    }
    
    
    void add(int key) {
        root = insert(root, key);
    }
    
    void remove(int key) {
        root = deleteNode(root, key);
    }
    
    bool contains(int key) {
        TreeNode* node = root;
        while(node){
            if(node->val > key){
                node =node->left;
            } else if(node->val < key){
                node = node->right;
            } else return true;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */