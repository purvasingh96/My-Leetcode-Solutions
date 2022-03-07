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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* left=list1;
        ListNode* right=list2;
        
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        
        while(left!=NULL && right!=NULL) {
            if(left->val < right->val) {
                res->next=new ListNode(left->val);
                left=left->next;
            } else {
                res->next = new ListNode(right->val);
                right=right->next;
            }
            
            res=res->next;
        }
        
        if(left) {
            res->next=left;
        }
        
        else if(right) {
            res->next=right;
        }
        
        return ans->next;
        
    }
};