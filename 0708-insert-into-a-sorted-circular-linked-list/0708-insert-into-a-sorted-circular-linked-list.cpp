/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int x) {
        if(!head){
            Node* newNode = new Node(x);
            newNode->next = newNode;
            return newNode;
        }
        Node* root = head;
        Node* prev = head;
        head = head->next;
        
        while(prev->next!=root){
            if(prev->val < head->val){
                if(x >= prev->val && x <= head->val){
                    break;
                }
            } else if(prev->val > head->val) {
                // last node
                if(prev->val <= x || x <= head->val){
                    break;
                }
            } else if(prev->val == head->val){
                if(x == prev->val){
                    break;
                }
            }
            prev = prev->next;
            head=head->next;
        }
        
        Node* newNode = new Node(x);
        prev->next = newNode;
        newNode->next = head;
        
        return root;
    }
};