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
        if(!head || !head->next) return head;
        ListNode* less = new ListNode(0);
        ListNode* ans = less;
        ListNode* greater = new ListNode(0);
        ListNode* temp_greater = greater;
        
        ListNode* temp = head;
        
        while(temp){
            if(temp->val < x) {
                less->next = new ListNode(temp->val);
                less = less->next;
            } else {
                greater->next = new ListNode(temp->val);
                greater = greater->next;
            }
            temp = temp->next;
        }
        
        less->next = temp_greater->next;
        return ans->next;
    }
};