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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1);
        ListNode* ans = head;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            head = head->next;
        }
        while(l1){
            head->next = l1;
            break;
        }
        while(l2){
            head->next = l2;
            break;
        }
        
        return ans->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        int interval=1;
        
        while(interval < lists.size()){
            for(int i=0;i+interval<lists.size();i+=interval*2){
                lists[i] = merge(lists[i], lists[i+interval]);
            }
            interval *=2;
        }
        
        return lists[0];
        
        
    }
};