class Node{
public:
    string val;
    Node* prev;
    Node* next;
    Node(string val){
        this->val = val;
        prev=NULL;
        next=NULL;
    }
};

class BrowserHistory {
public:
    Node* root;
    
    BrowserHistory(string homepage) {
        root=new Node(homepage);    
    }
    
    void visit(string url) {
        root->next=NULL;
        Node* temp = new Node(url);
        root->next = temp;
        temp->prev = root;
        root=root->next;
    }
    
    string back(int steps) {
        Node* temp = root;
        while(steps && temp->prev!=NULL){
            temp=temp->prev;
            steps = steps-1;
        }
        root=temp;
        return root->val;
    }
    
    string forward(int steps) {
        Node* temp = root;
        while(steps && temp->next!=NULL){
            temp=temp->next;
            steps -=1;
        }
        root=temp;
        return root->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */