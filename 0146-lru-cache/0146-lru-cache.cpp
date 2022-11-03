class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev =NULL;
        this->next = NULL;
    }
};


class LRUCache {
private:
    unordered_map<int, Node*> m;
    int capacity;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev=head;
    }
    
    
    void remove(Node* t){
        m.erase(t->key);
        t->next->prev = t->prev;
        t->prev->next = t->next;
    }
    
    void insertFront(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        m[node->key] = node;
        
    }
    
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node* node = m[key];
        remove(node);
        insertFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        Node* node = new Node(key, value);
        if(m.find(key) != m.end()) {
            remove(m[key]);
        } else if(m.size() == capacity){
            remove(tail->prev);
        }
        insertFront(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */