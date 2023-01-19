class HitCounter {
private:
    vector<int> res;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        res.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int n = res.size();
        int idx = upper_bound(res.begin(), res.end(), timestamp-300) - res.begin();
        return n-idx;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */