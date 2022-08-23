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
        vector<int> ans;
        
        while(fast && fast->next){
            ans.push_back(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        while(slow){
            if(slow->val!=ans.back()) {
                if(slow->next){
                    if(slow->next->val!=ans.back()) return false;
                    else slow=slow->next;
                } else return false;
            }
            
            
            ans.pop_back();
            slow=slow->next;
        }
        
        return ans.size()==0;
        
    }
};