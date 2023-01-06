class CustomNode{
public:
    CustomNode* next;
    CustomNode* prev;
    int val, key;
    CustomNode(int key, int val) {
        this->val = val;
        this->key = key;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private:
    int n, cap;
    CustomNode* head;
    CustomNode* tail;
    map<int, CustomNode*> m;
public:
    LRUCache(int capacity) {
        this->cap = 0;
        this->n = capacity;    
        this->head = new CustomNode(0, 0);
        this->tail = new CustomNode(0, 0);
        this->tail->next = head;
        this->head->prev = tail;
    }
    
    void remove(CustomNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        m.erase(node->key);
    }
    
    void addFront(CustomNode* node){
        CustomNode* temp = head->prev;
        temp->next = node;
        node->prev = temp;
        node->next = head;
        head->prev = node;
        m[node->key] = node;
    }
    

    int get(int key) {
        // for(auto x:m){
        //     cout<<x.first<<"\n";
        // }
        //cout<<"\n====\n";
        if(m.find(key) == m.end()) return -1;
        CustomNode* k = m[key];
        
        remove(k);
        addFront(k);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            CustomNode* temp = m[key];
            remove(temp);
            temp->val = value;
            addFront(temp);
        } else{
           if(m.size() == n){
                remove(tail->next);
            }

            CustomNode* node = new CustomNode(key, value);
            addFront(node); 
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */