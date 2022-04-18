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
        
        Node* ans=head;
        
        while(head->val < head->next->val) head=head->next;
        
        head=head->next;
        
        cout<<head->next->val;
        
        Node* curr = head->next;
        Node* prev=head;
        
        while(true) {
            
            int x = insertVal;
            int y = prev->val;
            int z = curr->val;
            
            if((y <= x && x<= z)) {
                prev->next=newnode;
                newnode->next=curr;
                break;
            }
            
            if(y>=z && (x<z || x>y)){
                while(prev->val <= curr->val) {
                    if(prev->next==head) break;
                    prev=prev->next;
                    curr=curr->next;
                }
                //cout<<prev->val<<" "<<curr->val;
                prev->next=newnode;
                newnode->next=curr;
                break;
                
            }
                
            
            prev=curr;
            curr=curr->next;
        }
     
        return ans;
    }
};