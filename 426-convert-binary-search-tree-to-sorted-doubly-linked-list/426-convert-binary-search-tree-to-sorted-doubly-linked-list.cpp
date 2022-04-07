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
    Node* findPredecessor(Node* root){
        Node* curr=root->left;
        while(curr->right!=nullptr && curr->right!=root)
            curr=curr->right;
        return curr;
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node* curr = root;
        Node* prev = NULL;
        Node* start = NULL;
        
        while(curr) {
            
             if(curr->left==nullptr){
                if(prev!=nullptr){
                    prev->right=curr;
                    curr->left=prev;
                }
                else
                    start=curr;
                prev=curr;
                curr=curr->right;
            } else {
                
                Node* predecesor = findPredecessor(curr);
                
                if(predecesor->right==nullptr){
                    predecesor->right=curr;
                    curr=curr->left;
                }  else{
                    //predecesor->right=nullptr;
                    if(prev!=nullptr){
                        prev->right=curr;
                        curr->left=prev;
                    }
                    else
                        start=curr;
                    prev=curr;
                    curr=curr->right;
                }
                
                
            }
            
            
        }
        
        
        
        curr=root;
        while(curr->right!=nullptr)
            curr=curr->right;
        
        start->left=curr;
        curr->right=start;
        return start;
        
        
    }
};