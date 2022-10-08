class HitCounter {
private:
    vector<int> time;
    vector<int> hits;
public:
    HitCounter() {
        time.resize(300, 0);
        hits.resize(300, 0);
    }
    
    void hit(int timestamp) {
        int idx=timestamp%300;
        if(time[idx]!=timestamp){
            time[idx] = timestamp;
            hits[idx] = 1;
        } else{
            hits[idx]+=1;
        }
    }
    
    int getHits(int timestamp) {
        int c=0;
        for(int i=0;i<300;i++){
            if(timestamp - time[i] < 300) {
                c+=hits[i];
            }
        }
        
        return c;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */