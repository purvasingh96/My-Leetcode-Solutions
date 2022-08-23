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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        ListNode* slow=head;
        ListNode* fast = head;
        ListNode* prev=slow;
        vector<int> ans;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        
        ListNode* x=NULL;
        
        while(slow){
            ListNode* temp = slow->next;
            slow->next=x;
            x=slow;
            slow=temp;
        }
        
        while(head && x){
            if(head->val != x->val) return false;
            head=head->next;
            x=x->next;
        }
        
        return true;
        
    }
};