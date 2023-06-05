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
    ListNode* reverseList(ListNode* t){
        int n =0;
        ListNode* temp = t;
        ListNode* prev = NULL;
        while(temp){
            ListNode* next = temp->next;
            temp->next=prev;
            prev = temp;
            temp = next;
            ++n;
        }
        
        return prev;
    }
   
    
public:
    int pairSum(ListNode* head) {
        ListNode* fast =head;
        ListNode* slow = head;
        ListNode* prev = slow;
        while(fast){
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next=NULL;
        ListNode* rev = reverseList(slow);
        
        int ans=INT_MIN;
        while(head){
            int sum = head->val + rev->val;
            ans = max(ans, sum);
            head=head->next;
            rev = rev->next;
        }
        
        return ans;
        
    }
};