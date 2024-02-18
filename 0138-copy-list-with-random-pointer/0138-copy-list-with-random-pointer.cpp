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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* ans = head;
        while(head){
            
            if(m.find(head)==m.end()){
                Node* node = new Node(head->val);
                m[head] = node;
            }
            
                if(head->next){
                    if(m.find(head->next)==m.end()){
                        m[head->next] = new Node(head->next->val);
                    }
                    m[head]->next = m[head->next];
                }
                if(head->random){
                    if(m.find(head->random)==m.end()){
                        m[head->random] = new Node(head->random->val);
                    }
                    m[head]->random = m[head->random];
                
            }
            head = head->next;
        }
        
        return m[ans];
        
    }
};