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
class MyComp{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyComp> pq;
        for(auto x:lists) {
           if(x) pq.push(x);
        }
        ListNode* head=new ListNode(-1);
        ListNode* ans = head;
        
        while(!pq.empty()){
            auto f = pq.top();pq.pop();
            if(f){
                head->next=new ListNode(f->val);
                head=head->next;
                if(f->next) pq.push(f->next);    
            }
            
        }
        
        return ans->next;
    }
};