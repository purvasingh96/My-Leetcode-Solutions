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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
        ListNode* ha = a;
        ListNode* hb = b;
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        
        while(ha && hb) {
            
            if(ha->val <= hb->val) {
                res->next = new ListNode(ha->val);
                ha = ha->next;
            } else {
                res->next = new ListNode(hb->val);
                hb = hb->next;
            }
            res=res->next;
        }
        
        if(ha) {
            while(ha) {
                res->next = new ListNode(ha->val);
                ha = ha->next;
                res=res->next;
            }
        } else if(hb) {
            while(hb) {
                res->next = new ListNode(hb->val);
                hb = hb->next;
                res=res->next;
            }
        }
        
        return ans->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        int i=0 ,last = lists.size()-1;
        
        while(last > i) {
            
            int i=0, j=last;
            
            while(i<j) {
                
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i+=1;
                j-=1;
                
                if(i>=j) last = j;
                
            }
            
        }
        
        return lists[0];
        
    }
};