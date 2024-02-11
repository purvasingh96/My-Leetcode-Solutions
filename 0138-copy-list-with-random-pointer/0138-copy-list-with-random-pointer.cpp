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
        // clone problems
        map<Node*, Node*> m;
        Node* ans = head;
        
        while(head){
            
            Node* newNode = m.find(head) == m.end() ? new Node(head->val) : m[head];
            m[head] = newNode;
            // find next Node
            Node* next = head->next;
            if(next == NULL){
                newNode->next = NULL;
            }
            else{
                if(m.find(next) == m.end()){
                    Node* nextNode = new Node(next->val);
                    m[next] = nextNode;
                }
                m[head]->next = m[next];
            }
            
            
            // find random node
            
            Node* random = head->random;
        
            if(random == NULL){
                newNode->random = NULL;
            }
            else {
                if(m.find(random) == m.end()){
                    Node* randomNode = new Node(random->val);
                    m[random] = randomNode;
                }

                m[head]->random = m[random];
            }
            
            
            //m[head] = newNode;     
            head=head->next;
        }
        
        return m[ans];
    }
};