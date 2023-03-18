class Node{
public:
    Node* next;
    Node* prev;
    string web;
    Node(string web){
        this->web = web;
        this->prev=NULL;
        this->next=NULL;
    }
};

class BrowserHistory {
private:
    Node* curr;
public:
    BrowserHistory(string homepage) {
        Node* head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {
        Node* prev = curr;
        curr->next = new Node(url);
        curr=curr->next;
        curr->prev=prev;
        
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps--){
            curr=curr->prev;
        }
        return curr->web;
    }
    
    string forward(int steps) {
        while(curr->next && steps--){
            curr = curr->next;
        }
        return curr->web;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */