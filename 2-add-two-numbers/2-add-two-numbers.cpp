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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* res =new ListNode(0);
        ListNode* ans = res;
        
        while(l1 && l2) {
            
            int sum = carry + l1->val + l2->val;
            res->next = new ListNode(sum%10);
            carry = sum/10;
            
            l1=l1->next;
            l2=l2->next;
            res=res->next;
            
        }
        
        if(l1 || l2) {
            ListNode* dummy = NULL;
            
            if(l1) {
                dummy = l1;
            } else {
                dummy = l2;
            }
            
            while(dummy) {
                
                int sum = carry + dummy->val;
                res->next = new ListNode(sum%10);
                carry = sum/10;

                dummy=dummy->next;
                res=res->next;
                
            }
            
            
        } 
        
        if(carry) {
            res->next = new ListNode(carry);
        }
        
        return ans->next;
        
    }
};