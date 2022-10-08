class HitCounter {
private:
    queue<int> q;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        if(timestamp-300 <= 0) return q.size();
        while(!q.empty() && q.front() <= (timestamp - 300)) q.pop();
        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */