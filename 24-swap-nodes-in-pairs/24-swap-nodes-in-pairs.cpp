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
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL) {
            
            ListNode* temp = curr->next;
            if(temp==NULL) break;
            curr->next = temp->next;
            temp->next = curr;
            if(prev!=NULL) prev->next = temp;
            prev=curr;
            curr = curr->next;
            
        }
        
        return ans;
    }
};