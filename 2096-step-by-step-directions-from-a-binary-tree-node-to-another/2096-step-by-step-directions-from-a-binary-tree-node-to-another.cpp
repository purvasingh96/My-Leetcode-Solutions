class Solution {
public:
    TreeNode* lca(TreeNode *root, int startValue, int destValue) {
        if(!root) return NULL;
        if(root->val == startValue) return root;
        if(root->val == destValue) return root;
        auto l = lca(root->left, startValue, destValue);
        auto r = lca(root->right, startValue, destValue);
        if(l && r) return root;
        return l ? l : r;
    }
    bool getPath(TreeNode *root, int value, string &path) {
        if(!root) return false;
        if(root->val == value) return true;
        path += 'L';
        auto res = getPath(root->left, value, path);
        if(res) return true;
        path.pop_back();
        path += 'R';
        res = getPath(root->right, value, path);
        if(res) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        string p1, p2;
        getPath(root, startValue, p1);
        getPath(root, destValue, p2);
        for(auto &c : p1) c = 'U';
        return p1 + p2;
    }
};