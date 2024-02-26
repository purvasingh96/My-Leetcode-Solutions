class RandomizedSet {
public:
    unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            m[val]+=1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = rand()%(m.size());
        auto it = next(m.begin(), idx);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */