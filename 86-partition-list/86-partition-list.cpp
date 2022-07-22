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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* start = new ListNode(-201);
        start->next = head;
        ListNode* lsmall = start;
        
        ListNode* prev = head;
        
        if(!head || !head->next) return head;
        
        while(head!=NULL){
            
            if(head->val<x){
                
                if(lsmall->next == head){
                    //cout<<"hre";
                    lsmall = head;
                    prev = head;
                    head=head->next;
                } else{
                    
                    prev->next = head->next;
                    ListNode* t = lsmall->next;
                    lsmall->next = head;
                    head->next = t;
                    lsmall = head;
                    head = prev->next;
                }
                
            } else {
                prev = head;
                head = head->next;
            }
            
        }
        
        return start->next;
    }
};