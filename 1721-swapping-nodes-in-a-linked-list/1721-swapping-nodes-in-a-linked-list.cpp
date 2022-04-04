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
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength=0;
        ListNode* frontNode=NULL;
        ListNode* endNode = NULL;
        ListNode* currNode = head;
        
        while(currNode) {
            
            listLength +=1;
            if(endNode) {
                endNode = endNode->next;
            }
            
            if(listLength == k) {
                frontNode = currNode;
                endNode=head;
            }
            
            currNode = currNode->next;
            
        }
        
        swap(frontNode->val, endNode->val);
        return head;
        
    }
};