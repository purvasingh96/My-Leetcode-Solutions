class LUPrefix {
private:
    vector<bool> memo;
    int lastLPSIndex;
    int sz;
public:
    LUPrefix(int n) {
        memo.resize(n+1, false);
        sz=n;
        lastLPSIndex=0;
    }
    
    void upload(int video) {
        memo[video] = true;
        
        if(lastLPSIndex==0){
            int i=1;
            while(i<sz+1 && memo[i]==true) i+=1;
            lastLPSIndex = i-1;
        }
        
        else if(video == lastLPSIndex+1) {
            int i=video;
            while(i<sz+1 && memo[i]==true) i+=1;
            lastLPSIndex = i-1;    
        }
        
    }
    
    int longest() {
        return lastLPSIndex;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */