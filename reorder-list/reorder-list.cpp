/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
            
        while(head!=NULL) {
            ListNode* temp = head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
        
    }
    
    void mergeList(ListNode* h1, ListNode* h2) {
        
        ListNode* temp = h1;
        
        while(temp!=NULL && h2!=NULL) {
            ListNode* t1 = temp->next;
            temp->next=h2;
            ListNode* t2 = h2->next;
            h2->next=t1;
            temp=t1;
            h2=t2;
        }
        
        
    }
    
    void reorderList(ListNode* head) {
        /*
        Pseudocode:
            - find middle node
            - create two LL
            - reverse 2nd half of LL
            - Merge sort
        TC:
        SC:
        */
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* secondHead = slow->next;
        slow->next=NULL;
        
        ListNode* revHead = reverseList(secondHead);
        mergeList(head, revHead);
        
        
    }
};