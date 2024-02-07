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
        Node* newNode = new Node(x);
        bool insert=false;
        
        if(!head){
            newNode->next = newNode;
            return newNode;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        
        while(prev->next!=head){
            if(prev->val < curr->val){
                if(prev->val <= x && x<= curr->val){
                    // insert in between
                    cout<<"insert!";
                    insert=true;
                }
            } else if(prev->val > curr->val){
                if(x<=curr->val || x>= prev->val) {
                    // insert in front/back
                   insert = true;
                }
            } 
            if(insert){
                Node* temp = prev->next;
                prev->next = newNode;
                newNode->next = temp;
                return head;
            }
            prev=prev->next;
            curr=curr->next;
            
        }
        
        Node* temp = prev->next;
        prev->next = newNode;
        newNode->next = temp;
        return head;
    }
};