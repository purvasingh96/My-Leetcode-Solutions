class MyHashSet {
    TreeNode *root;
public:
    MyHashSet() {
        root=NULL;
    }
    
    TreeNode *insert(TreeNode *root,int key)
    {
        if(root==NULL)
        {
            return new TreeNode(key);
        }
        if(root->val>key)
            root->left=insert(root->left,key);
        else if(root->val<key)
            root->right=insert(root->right,key);
        else
            root->val=key;
        return root;
    }
    void add(int key) {
        root=insert(root,key);
    }
    
    TreeNode *del(TreeNode *root,int key)
    {
        if(root==NULL)
            return NULL;
        if(root->val>key)
            root->left=del(root->left,key);
        else if(root->val<key)
            root->right=del(root->right,key);
        else
        {
            if(!root->left && !root->right)
                return NULL;
            else if(root->left && !root->right)
                return root->left;
            else if(!root->left && root->right)
                return root->right;
            else
            {
                TreeNode *node=root->left;
                while(node->right)
                    node=node->right;
                root->val=node->val;
                root->left=del(root->left,root->val);
            }
        }
        return root;
    }
    void remove(int key) {
        root=del(root,key);
    }
    
    bool contains(int key) {
        TreeNode *node=root;
        while(node)
        {
            if(node->val>key)
                node=node->left;
            else if(node->val<key)
                node=node->right;
            else
                return true;
        }
        return false;
    }
};