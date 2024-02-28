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
        if(!head){
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        Node* prev = head;
        Node* ans = head;
        head = head->next;
        bool insertHere=false;
        
        
        while(head!=ans){
            if(prev->val <= head->val){
                if(insertVal >= prev->val && insertVal <= head->val){
                    break;
                }
            } else {
                // inserting towards the end/first
                if(insertVal > prev->val || insertVal < head->val){
                    break;
                }
            }
            
            prev=prev->next;
            head=head->next;
        }
        
        Node* newNode = new Node(insertVal);
        prev->next = newNode;
        newNode->next = head;
        return ans;
        
    }
};