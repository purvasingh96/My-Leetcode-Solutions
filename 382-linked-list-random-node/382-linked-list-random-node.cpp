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
    ListNode* curr;
    Solution(ListNode* head) {
        curr=head;
    }
    
    int getRandom() {
        int index = 1;
        int ans=0;
        ListNode* res = curr;
        
        while(res) {
            if(rand() % index == 0) {
                ans = res->val;
            }
            
            index+=1;
            res=res->next;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */