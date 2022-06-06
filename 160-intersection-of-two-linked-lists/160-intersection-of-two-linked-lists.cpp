/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int findLen(ListNode* node){
        ListNode* temp = node;
        int len=0;
        
        while(node!=NULL){
            node=node->next;
            len+=1;
        }
        
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)     {
        
        int len_a = findLen(headA);
        int len_b = findLen(headB);
        
        ListNode* minlen=headA;
        ListNode* maxlen=headB;
        
        if(len_a>len_b){
            minlen = headB;
            maxlen = headA;
        } 
        
        int diff = abs(len_a - len_b);
        
        while(maxlen!=NULL && diff!=0){
            maxlen=maxlen->next; 
            diff-=1;
        }
        
        while(minlen && maxlen){
            if(minlen == maxlen) 
                return minlen;
            minlen=minlen->next;
            maxlen=maxlen->next;
        }
        
        
        return NULL;
        
    }
};