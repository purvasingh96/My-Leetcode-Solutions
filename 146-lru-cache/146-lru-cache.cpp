class node {
public:
    int key;
    int value;
    node* prev;
    node* next;
    
    node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, node*> m;
    int cap;
    node* head = new node(0, 0);
    node* tail = new node(0, 0);
    
    LRUCache(int capacity) {
        
        this->cap = capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    // helper functions
    void insert(node* currnode) {
        
        currnode->next=head->next;
        head->next->prev=currnode;
        currnode->prev=head;
        head->next=currnode;
        
        m[currnode->key]=currnode;
        
    }
    
    
    void remove(node* currnode) {
        m.erase(currnode->key);
        currnode->next->prev=currnode->prev;
        currnode->prev->next = currnode->next;
    }
    
    
    int get(int key) {
        
        if(m.find(key)==m.end()) return -1;
        
        node* currnode = m[key];
        remove(currnode);
        insert(currnode);
        
        return currnode->value;
        
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()) {
            remove(m[key]);
        }
        
        if(m.size()==cap) {
            remove(tail->prev);
        }
        
        insert(new node(key, value));
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
PUT Function

1. we check in map if key is present or not:
    if key is present:
            * extract node from map, 
            * remove that node
            * add node with updated value to both map and DLL
    else:
        if size == capacity:
            * remove least recently used
            * add new node
        else:
            * add new node
        
GET FUNCTION
1. if key is present in map:   
        * return value of this key
        * also update this to be the recently used node
    else:
        return -1

*/