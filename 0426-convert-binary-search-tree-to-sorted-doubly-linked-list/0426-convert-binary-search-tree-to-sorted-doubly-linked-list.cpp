/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    Node* firstNode;
    Node* dfs(Node* root){
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        
        Node* l = dfs(root->left);
        Node* r = dfs(root->right);
        
        if(l){
            Node* t = l;
            while(t->right){
                t = t->right;
            }
            t->right = root;
            root->left = t;
        }
        if(r){
            Node* t = r;
            while(t->left){
                t = t->left;
            }
            root->right = t;
            t->left = root;
        }
        
        
        return root;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* ans =  dfs(root);
        Node* first = ans;
        while(first->left){
            first = first->left;
        }
        
        Node* last = ans;
        while(last->right){
            last = last->right;
        }
        
        first->left = last;
        last->right = first;
        return first;
    }
};