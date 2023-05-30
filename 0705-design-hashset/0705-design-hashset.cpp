class MyHashSet {
private:
    vector<set<int>> res;
    int hashkey;
public:
    MyHashSet() {
        hashkey = 769;
        res.resize(hashkey);
    }
    
    int hashindex(int key){
        return key%hashkey;
    }
    
    void add(int key) {
        int i = hashindex(key);
        res[i].insert(key);
    }
    
    void remove(int key) {
        int i = hashindex(key);
        res[i].erase(key);
    }
    
    bool contains(int key) {
        int i = hashindex(key);
        return res[i].find(key)!=res[i].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */