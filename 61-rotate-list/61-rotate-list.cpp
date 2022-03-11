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
    
    int nodeLength(ListNode* head) {
        ListNode* temp = head;
        int len=0;
        while(temp) {
            len+=1;
            temp=temp->next;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int len = nodeLength(head);
        k = k%len;
        if(k == 0) return head;
        k = len - k;
        //cout<<len<<" "<<k;
        int i=1;
        ListNode* temp = head;
        
        while(i!=k) {
            i+=1;
            temp = temp->next;
        }
        
        ListNode* head_2 = temp->next;
        temp->next=NULL;
        ListNode* ans = head_2;
        
        while(head_2->next!=NULL) {
            head_2 = head_2->next;
        }
        
        head_2->next = head;
        return ans;
        
    }
};