/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    
    Node* getClonedNode(Node* head) {
        if(head!=NULL) {
            
            if(m.find(head)!=m.end()) {
                return m[head];
            } else {
                
                m[head] = new Node(head->val);
                return m[head];
                
            }
            
        }        
        return NULL;
    }
    
    Node* copyRandomList(Node* head) {
        
        if(!head) {
            return NULL;
        }
        
        Node* res = head;
        Node* clonedNode = new Node(head->val);
        m[head] = clonedNode;
        
        while(head) {
            clonedNode->next = getClonedNode(head->next);
            clonedNode->random = getClonedNode(head->random);
            head=head->next;
            clonedNode=clonedNode->next;
        }
        
        return m[res];
    }
};