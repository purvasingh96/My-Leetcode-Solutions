class SmallestInfiniteSet {
private:
    vector<bool> live;
public:
    SmallestInfiniteSet() {
        live.resize(1001, true);
    }
    
    int popSmallest() {
        for(int i=1;i<live.size();i++){
            if(live[i]){
                live[i]=false;
                return i;
            }
        }
        
        return 0;
    }
    
    void addBack(int num) {
        if(live[num]==false) {
            live[num]=true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */