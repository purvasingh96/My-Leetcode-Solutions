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
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, MyComp> pq;
        
        for(auto l: lists) {
            if(l) {
                pq.push(l);
            }
        }
        
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        
        while(!pq.empty()) {
            ListNode* temp = pq.top();
            res->next = pq.top();
            pq.pop();
            res = res->next;
            
            if(temp->next) {
                pq.push(temp->next);
            }
        }
        
        return ans->next;
        
    }
};