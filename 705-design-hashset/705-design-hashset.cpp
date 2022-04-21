class MyHashSet {
private:
    vector<int> m;
public:
    MyHashSet() {
        m.resize(1000001, -1);
    }
    
    void add(int key) {
        m[key] +=1;
    }
    
    void remove(int key) {
        m[key]=-1;
    }
    
    bool contains(int key) {
        return m[key] != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */