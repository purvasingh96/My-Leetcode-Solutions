/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    Node* prev; // tracks nodes on curr+1 level;
    Node* leftmost; // head of curr+1 level
    
    
    void processChild(Node* child) {
        if(child!=NULL) {
            
            if(prev == NULL) {
                this->leftmost = child;
            } else{
                prev->next = child;
            }
            prev=child;
        }
        
    }
public:
    Node* connect(Node* root) {
        
        
        if(!root) return root;
        this->leftmost = root;
        
        Node* curr; // head of curr level
        curr = this->leftmost;
        
        while(this->leftmost!=NULL) {
            
            this->prev=NULL;
            curr=this->leftmost;
            this->leftmost=NULL;
            
            while(curr!=NULL) {
                processChild(curr->left);
                processChild(curr->right);
                curr = curr->next;
            }
            
        }
        
        return root;
        
    }
};