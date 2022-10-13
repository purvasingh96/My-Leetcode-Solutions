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
class MyCompare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        priority_queue<ListNode*, vector<ListNode*>, MyCompare> pq;
        for(auto x:lists){
            if(x) pq.push(x);
        }
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            res->next = new ListNode(f->val);
            res=res->next;
            f=f->next;
            if(f) pq.push(f);
        }
        
        return ans->next;
    
    }
};