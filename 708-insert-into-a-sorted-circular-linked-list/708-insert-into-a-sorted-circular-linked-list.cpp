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
    Node* insert(Node* head, int insertVal) {
        Node* newnode = new Node(insertVal);
        
        if(head==NULL) {
            newnode->next=newnode;
            return newnode;
        }
        
        Node* node=head;
       
        while(node->next!=head) {
            
            if(node->val<=node->next->val) {
                
                // basic check
                if(node->val <= insertVal && insertVal<=node->next->val) {
                    break;
                }
                
            } else {
                
                if(node->val <= insertVal || insertVal<=node->next->val){
                    break;
                }
                
            }
            
            node=node->next;
            
        }
        
        Node* next = node->next;
        node->next = new Node(insertVal, next);
        return head;
    }
};