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
        bool insert=false;
        if(!head){
            Node* newNode = new Node(x);
            newNode->next = newNode;
            return newNode;
        }
        Node* prev=head;
        Node* next = head->next;
        
        while(next!=head){
            if(prev->val < next->val){
                if(prev->val <= x && x<=next->val){
                    insert=true;
                }
            } else if(prev->val == next->val){
                if(x == prev->val){
                    insert=true;
                }
            } else if(prev->val > next->val){
                if(x > prev->val || x < next->val){
                    insert=true;
                }
            }
            
            if(insert){
                Node* nextNode = prev->next;
                Node* newNode = new Node(x);
                prev->next = newNode;
                newNode->next = nextNode;
                break;
            } else {
                prev = prev->next;
                next = next->next;
            }
        }
        
        if(!insert){
            Node* nextNode = prev->next;
            Node* newNode = new Node(x);
            prev->next = newNode;
            newNode->next = nextNode;
        }
        
        return head;
    }
};