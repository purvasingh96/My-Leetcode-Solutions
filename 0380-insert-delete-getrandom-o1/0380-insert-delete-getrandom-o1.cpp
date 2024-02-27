class RandomizedSet {
public:
    vector<int> res;
    
    unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()){
            return false;
        }
        res.push_back(val);
        m[val] = res.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()){
            return false;
        }
        int pos = m[val];
        int elem = res.back();
        
        if(pos != res.size()-1) {
            swap(res[pos], res[res.size()-1]);
            m[elem] = pos;
        }
        
        m.erase(val);
        res.pop_back();
        return true;
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