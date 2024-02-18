class Node{
public:
    Node* next;
    Node* prev;
    int val;
    int key;
    Node(int k, int v){
        val = v;
        key = k;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
     Node* head;
    Node* last;
    int c;
    unordered_map<int, Node*> m;
    
    void insertFront(Node* node){
        
        Node* temp = last->prev;
        temp->next = node;
        node->prev=temp;
        node->next=last;
        last->prev=node;
        m[node->key] = node;
    }
    
    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next =next;
        next->prev = prev;
        m.erase(node->key);
    }
    
    LRUCache(int capacity) {
        c = capacity;
        head = new Node(0, 0);
        last = new Node(0, 0);
        
        head->next =last;
        last->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* node = m[key];
        deleteNode(node);
        insertFront(node);
        return m[key]->val;
    }
    
    void put(int key, int value) {
       
        Node* node;
        if(m.find(key)!=m.end()){
            node = m[key];
            deleteNode(node);
            node->val = value;
        } else {
             if(m.size() == c){
                // already at capacity
                deleteNode(head->next);
            }

            node = new Node(key, value);
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