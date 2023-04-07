class Node{
 public:
    Node* next;
    Node* prev;
    int key;
    int val;
    Node(int key, int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
private:
    Node* h;
    Node* t;
    int c;
    int capacity;
    unordered_map<int, Node*> m;
public:
    LRUCache(int capacity) {
        c=0;
        this->capacity = capacity;
        h = new Node(-1, -1);
        t = new Node(-1, -1);
        h->next=t;
        t->prev=h;
    }
    
    void removeNode(Node* node){
        Node* prev=node->prev;
        prev->next=node->next;
        node->next->prev=prev;
        m.erase(node->key);
        c-=1;
    }
    
    void insertNodeInFront(Node* node){
        Node* prev = t->prev;
        prev->next=node;
        node->prev=prev;
        node->next=t;
        t->prev=node;
        m[node->key] = node;
        c+=1;
    }
    
    int get(int key) {
        //cout<<"getting: "<<key<<"\n";
        if(m.find(key)==m.end()) return -1;
        Node* node = m[key];
        removeNode(node);
        insertNodeInFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            removeNode(node);
            node->val = value;
            insertNodeInFront(node);
        } else {
            //cout<<"cap before: "<<c<<" "<<capacity<<"\n";
            if(c==capacity) removeNode(h->next);
            //cout<<"cap after: "<<c<<"\n";
            Node* node = new Node(key, value);
            //cout<<"inserting: "<<node->key<<"\n";
            
            insertNodeInFront(node);
            //cout<<"h->next: "<<h->next->key<<"\n";
            //cout<<"t->prev: "<<t->prev->key<<"\n";
            
            m[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */