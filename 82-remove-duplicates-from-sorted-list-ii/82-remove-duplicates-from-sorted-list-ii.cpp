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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* left = head;
        ListNode* prev = new ListNode(200);
        prev->next=head;
        ListNode* res = prev;
        
        while(left!=NULL) {
            
            if(left->next && left->val == left->next->val) {
                int cur_val = left->val;
                
                while(left!=NULL && left->val == cur_val) {
                    left=left->next;
                }
                prev->next=left;
                
                
            } else {
                prev = left;
                left = left->next;
            }
            
        }
        
        return res->next;
    }
};