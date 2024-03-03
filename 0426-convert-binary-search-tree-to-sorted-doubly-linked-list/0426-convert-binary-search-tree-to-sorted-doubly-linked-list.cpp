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

public:
    Node* treeToDoublyList(Node* root) {
        if(!root){
            return NULL;
        }
        Node* head = new Node(-1);
        Node* last = head;
        while(root){
            if(root->left==NULL){
                last->right = root;
                root->left=last;
                last =root;
                root=root->right;
            } else {
                Node* pred = root->left;
                while(pred->right!=NULL && pred->right!=root){
                    pred = pred->right;
                }
                
                if(pred->right==NULL){
                    pred->right=root;
                    root=root->left;
                } else if(pred->right==root){
                    last->right = root;
                    root->left=last;
                    last =root;
                    root=root->right;
                }
            }
        }
        
        last->right = head->right;
        head->right->left = last;
        return head->right;
        
    }
};