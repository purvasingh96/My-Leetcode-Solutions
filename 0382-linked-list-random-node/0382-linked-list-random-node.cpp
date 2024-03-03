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
        _head=head;
    
    }
    
    int getRandom() {
        int ans=-1;
        int sz=0;
        ListNode* root = _head;
        
        while(root){
            if(ans==-1){
                ans = root->val;
                sz+=1;
            } else {
                sz+=1;
                int val = rand()%sz;
                if(val == 0){
                    ans = root->val;
                } 
            }
            root = root->next;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */