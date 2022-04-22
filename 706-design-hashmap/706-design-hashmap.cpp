class MyHashMap {
private:
    vector<vector<pair<int, int>>> buckets;
    int hashKey;
public:
    MyHashMap() {
        hashKey = 769;
        buckets.resize(hashKey);
    }
    
    int getIdx(int key) {
        return key%hashKey;
    }
    
    void put(int key, int value) {
        int idx = getIdx(key);
        
        vector<pair<int, int>>& bucket = buckets[idx];
        
        for(auto it=bucket.begin();it!=bucket.end();it++){
            
            if(it->first == key) {
                it->second = value;
                return;
            }
        }
        
        bucket.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int idx = getIdx(key);
        
        for(auto p: buckets[idx]) {
            if(p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = getIdx(key);
        
        for(int i=0;i<buckets[idx].size();i++) {
            if(buckets[idx][i].first == key) {
                buckets[idx].erase(buckets[idx].begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */