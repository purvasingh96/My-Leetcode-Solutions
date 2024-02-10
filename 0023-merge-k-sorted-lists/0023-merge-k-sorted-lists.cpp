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
private:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        ListNode* l1 = a;
        ListNode* l2 = b;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                res->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                res->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            res=res->next;
        }
        
        if(l1){
            res->next=l1;
        }
        
        if(l2){
            res->next=l2;
        }
        
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int interval=1;
        int amt = lists.size();
        
        while(interval < amt){
            for(int i=0;i<amt-interval;i+=interval*2){
                lists[i] = merge(lists[i], lists[i+interval]);
            }
            interval *=2;
        }
        
        return amt>0 ? lists[0] : NULL;
    }
};