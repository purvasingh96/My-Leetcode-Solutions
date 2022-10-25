class RandomizedSet {
private:
    vector<int> res;
    unordered_map<int, int> m;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            res.push_back(val);
            m[val] = res.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int og_idx = m[val];
            res[og_idx] = res.back();
            m[res.back()] = og_idx;
            res.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return res[rand()%(res.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */