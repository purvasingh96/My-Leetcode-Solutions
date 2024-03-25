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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start=list1;
        ListNode* prev = start;
        ListNode* end = list1;
        int i=0, j=a;
        
        while(i!=a){
            i+=1;
            prev=start;
            start=start->next;
        }
        prev->next = list2;
        while(prev->next){
            prev=prev->next;
        }
        
        while(j!=b){
            j+=1;
            start=start->next;
        }
        
        start = start->next;
        prev->next = start;
        return list1;
        
        
    }
};