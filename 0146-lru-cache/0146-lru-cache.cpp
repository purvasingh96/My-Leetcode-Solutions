class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v){
        this->key = k;
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    int cap;
    Node* head;
    Node* last;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(-1, -1);
        last = new Node(-1, -1);
        head->next = last;
        last->prev = head;
    }
    
    void removeNode(Node* target){
        Node* prev = target->prev;
        Node* next = target->next;
        prev->next = next;
        next->prev = prev;
        m.erase(m.find(target->key));
    }
    
    void insertNode(Node* target){
        if(m.size() == cap){
            removeNode(head->next);
        }
        Node* prev = last->prev;
        prev->next=target;
        target->prev = prev;
        target->next =last;
        last->prev = target;
        m[target->key] = target;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* target = m[key];
        removeNode(m[key]);
        insertNode(target);
        return m[target->key]->val;
    }
    
    void put(int key, int value) {
        Node* node= new Node(key, value);
        
        if(m.find(key)!=m.end()){
            removeNode(m[key]);
        }
        insertNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */