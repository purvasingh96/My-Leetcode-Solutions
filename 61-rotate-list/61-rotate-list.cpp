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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = 1, i=1;
        
        if(!head || !head->next) return head;
        
        ListNode* curr = head;
        
        while(curr->next!=NULL) {
            curr=curr->next;
            n+=1;
        }
        
        curr->next = head;
        
        k = k%n;
        
        ListNode* new_tail = head;
        
        while(i!=(n-k)) {
            
            new_tail = new_tail->next;
            i+=1;
            
        }
        
        ListNode* new_head = new_tail->next;
        new_tail->next=NULL;
        
        return new_head;
        
        
        
    }
    
    
};