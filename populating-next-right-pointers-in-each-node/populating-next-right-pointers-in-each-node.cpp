/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*
        Pseudo code:
            - do level order traversal
            - use queue, q, to keep track of nodes at each level 
                - pop front node, f
                    - if q's size==0
                        - f->next = NULL
                    - else
                        - f->next = q.front
        TC: O(H) 
        SC: O(N), N = max nodes in the queue at a time
        */
        
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int s = q.size();
            
            // level order
            while(s--) {
                
                Node* f = q.front();
                q.pop();
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
                if(s== 0) f->next = NULL;
                else f->next = q.front();
                
            }
            
            
            
        }
        
        return root;
         
    }
};