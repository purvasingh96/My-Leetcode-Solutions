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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ans = head->next;
        
        ListNode* prev = head;
        ListNode* t = head;
        
        while(prev->next){
            
            ListNode* next = t->next;
            t->next = next->next;
            next->next=t;
            prev=t;
            t = t->next;
            if(t && t->next) prev->next = t->next;
            else break;
        }
        
        return ans;
        
    }
};