class RandomizedSet {
public:
    vector<int> res;
    unordered_map<int,int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            res.push_back(val);
            m[val]=res.size()-1;
            return true;
        } 
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()){
            return false;
        }
        int pos = m[val];
        int back = res.back();
        m[back] = pos;
        res[pos] = back;
        res.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return res[rand()%res.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */