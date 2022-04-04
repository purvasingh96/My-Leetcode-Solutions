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
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* curr = head;
        
        while(k>0) {
            
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
            k-=1;
            
        }
        
        return prev;
            
    }
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr=head;
        ListNode* ktail = NULL;
        ListNode* new_head = NULL;
        
        while(curr) {
            
            int count=0;
            curr = head;
            
            while(curr && count<k) {
                
                curr = curr->next;
                count+=1;
                
            }
            
            
            if(count == k) {
                
                ListNode* rev_head = reverseList(head, k);
                
                if(new_head == NULL) new_head = rev_head;
                
                if(ktail!=NULL) ktail->next = rev_head;
                
                ktail = head;
                head = curr;
                
            }
            
            
        }
        
        if(ktail != NULL) {
            ktail->next=head;
        }
        
        return new_head == NULL?head:new_head;
        
    }
};