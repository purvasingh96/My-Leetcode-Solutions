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
    ListNode* _head;
    Solution(ListNode* head) {
        _head = head;
    }
    
    int getRandom() {
        ListNode* res = _head;
        int ans=-1, c=0;
        cout<<res->val;
        while(res){
            if(ans==-1){
                ans=res->val;
                c+=1;
            } else {
                c+=1;
                if(rand()%c==0){
                    ans = res->val;
                }
            }
             res = res->next;   
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */