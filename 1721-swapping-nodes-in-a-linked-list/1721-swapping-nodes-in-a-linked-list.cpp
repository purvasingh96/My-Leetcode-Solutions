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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* dummy = new ListNode(0);
        dummy->next=head;
        
        ListNode* first=dummy;
        ListNode* second = dummy;
        ListNode* currNode = dummy;
        
        for(int i=0;i<k;i++) {
            currNode=currNode->next;
        }
        
        first=currNode;
        
        while(currNode) {
            currNode=currNode->next;
            second = second->next;
        }
        
        //cout<<first->val<<" "<<second->val<<"\n";
        
        swap(first->val, second->val);
        return head;
        
    }
};