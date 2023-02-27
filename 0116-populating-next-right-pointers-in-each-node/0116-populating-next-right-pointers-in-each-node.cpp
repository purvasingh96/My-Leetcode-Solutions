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
        if(!root) return root;
        Node* curr = root;
        queue<Node*> q;
        q.push(curr);
        
        while(!q.empty()){
            int sz = q.size();
            Node* prev=NULL;
            while(sz--){
                auto f = q.front();q.pop();
                
                //cout<<f->val<<" ";
                if(prev) prev->next = f;
                prev=f;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        
        return root;
    }
};