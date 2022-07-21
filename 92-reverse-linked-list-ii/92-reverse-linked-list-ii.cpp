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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right) return head;
        ListNode* res = head;
        ListNode* ppl = NULL;
        ListNode* pl = NULL;
        int x =1;
        
        while(x!=left){
            
            ppl=head;
            pl=head;
            head=head->next;
            x+=1;
            
        }
        
        ListNode* start = head;
        
        while(x!=right+1){
            
            ListNode* t = head->next;
            head->next = pl;
            pl = head;
            head = t;
            x+=1;
            
        }
        
        
        if(ppl) ppl->next = pl;
        start->next = head;
        
        return left==1?pl:res;
            
    }
};